#include "Entity.h"

#include "Renderer/Renderer.h"

namespace Engine {
	Entity::Entity(float* bufferData, size_t bufferDataSize, unsigned int* indices, size_t indicesDataSize,
		const char* vertSrcFile, const char* fragSrcFile, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	{
		this->position = position;
		this->rotation = rotation;
		this->scale = scale;

		
		glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), this->position);
		glm::mat4 scaleMatrix = glm::scale(scale);
		glm::mat4 rotationMatrix = glm::eulerAngleXYZ(rotation.x, rotation.y, rotation.z);
		modelMatrix = translationMatrix * rotationMatrix * scaleMatrix;
		DebugLog(modelMatrix[3][0]);

		shader = std::make_shared<Shader>(vertSrcFile, fragSrcFile);
		VAO = std::make_shared<VertexArrayObject>();
		std::shared_ptr<IndexBufferObject> IBO = std::make_shared<IndexBufferObject>(indices, indicesDataSize);
		VAO->AddBuffer(std::make_shared<VertexBufferObject>(IBO, bufferData, bufferDataSize));

		Renderer::getInstance()->AddEntity(this);
	}

	void Entity::Draw() {
		// Bind shader
		shader->Bind();
		
		// Set Model View Projection Matrix
		GLuint MatrixID = glGetUniformLocation(shader->GetId(), "MVP");
		glm::mat4 MVP = Renderer::getInstance()->CalculateMVPMatrix(modelMatrix);
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

		// Draw Elements
		VAO->Bind();
		VAO->Draw();

		// Unbind
		VAO->Unbind();
		shader->Unbind();
	}
}
