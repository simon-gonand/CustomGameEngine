#include "Entity.h"

namespace Engine {
	Entity::Entity(float* bufferData, size_t bufferDataSize, unsigned int* indices, size_t indicesSize,
		const char* vertSrcFile, const char* fragSrcFile, glm::mat4 modelMatrix) : modelMatrix(modelMatrix)
	{
		shader = std::make_shared<Shader>(vertSrcFile, fragSrcFile);
		VAO = std::make_shared<VertexArrayObject>();
		std::shared_ptr<IndexBufferObject> IBO = std::make_shared<IndexBufferObject>(indices, indicesSize);
		VAO->AddBuffer(std::make_shared<VertexBufferObject>(IBO, bufferData, bufferDataSize));

		Renderer::getInstance()->AddVertexArray(VAO);
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
