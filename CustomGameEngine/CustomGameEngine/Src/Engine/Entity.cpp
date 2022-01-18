#include "Entity.h"

#include "Renderer/Renderer.h"

namespace Engine {
	Entity::Entity(float* bufferData, size_t bufferDataSize, unsigned int* indices, size_t indicesDataSize,
		const char* vertSrcFile, const char* fragSrcFile, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	{
		this->position = position;
		this->rotation = rotation;
		this->scale = scale;
		CalculateModelMatrix();

		shader = std::make_shared<Shader>(vertSrcFile, fragSrcFile);
		VAO = std::make_shared<VertexArrayObject>();
		std::shared_ptr<IndexBufferObject> IBO = std::make_shared<IndexBufferObject>(indices, indicesDataSize);
		VAO->AddBuffer(std::make_shared<VertexBufferObject>(IBO, bufferData, bufferDataSize));

		Renderer::GetInstance()->AddEntity(this);
	}

	glm::vec3 Entity::GetPosition()
	{
		return position;
	}

	glm::vec3 Entity::GetRotation()
	{
		return rotation;
	}

	glm::vec3 Entity::GetScale()
	{
		return scale;
	}

	void Entity::CalculateModelMatrix() {
		glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), position);
		glm::mat4 scaleMatrix = glm::scale(scale);
		glm::mat4 rotationMatrix = glm::eulerAngleXYZ(rotation.x, rotation.y, rotation.z);
		modelMatrix = translationMatrix * rotationMatrix * scaleMatrix;
	}

	void Entity::SetPosition(glm::vec3 position)
	{
		this->position = position;
		CalculateModelMatrix();
	}

	void Entity::SetRotation(glm::vec3 rotation) {
		this->rotation = rotation;
		CalculateModelMatrix();
	}

	void Entity::SetScale(glm::vec3 scale) {
		this->scale = scale;
		CalculateModelMatrix();
	}

	void Entity::Draw() {
		// Bind shader
		shader->Bind();
		
		// Set Model View Projection Matrix
		GLuint MatrixID = glGetUniformLocation(shader->GetId(), "MVP");
		glm::mat4 MVP = Renderer::GetInstance()->CalculateMVPMatrix(modelMatrix);
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

		// Draw Elements
		VAO->Bind();
		VAO->Draw();

		// Unbind
		VAO->Unbind();
		shader->Unbind();
	}

	void Entity::Update(float tick) 
	{
		
	}
}