#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include "Renderer/VertexArrayObject.h"
#include "Renderer/Shader.h"
#include "Logger/Logger.h"


namespace Engine {
	class Renderer;

	class Entity
	{
	private:
		glm::vec3 position;
		glm::vec3 scale;
		glm::vec3 rotation;
		glm::mat4 modelMatrix;
		
		std::shared_ptr<VertexArrayObject> VAO;

		std::shared_ptr<Shader> shader;

	public:
		Entity(float* bufferData, size_t bufferDataSize, unsigned int* indices, size_t indicesDataSize,
			const char* vertSrcFile, const char* fragSrcFile,
			glm::vec3 position = glm::vec3(0.0f), glm::vec3 rotation = glm::vec3(0.0f), glm::vec3 scale = glm::vec3(1.0f));
	
		void Draw();
	};
}