#pragma once

#include <glm/glm.hpp>

#include "Renderer/VertexArrayObject.h"
#include "Renderer/Shader.h"
#include "Renderer/Renderer.h"
#include"Logger/Logger.h"


namespace Engine {
	class VertexArrayObject;
	class Shader;

	class Entity
	{
	private:
		glm::mat4 modelMatrix;
		
		std::shared_ptr<VertexArrayObject> VAO;

		std::shared_ptr<Shader> shader;

	public:
		Entity(float* bufferData, size_t bufferDataSize, unsigned int* indices, size_t indicesDataSize,
			const char* vertSrcFile, const char* fragSrcFile, glm::mat4 modelMatrix = glm::mat4(1.0f));
	
		void Draw();
	};
}