#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../Logger/Logger.h"
#include "../Entity.h"

namespace Engine {
	class Renderer
	{
	private:
		static Renderer* _instance;

		Renderer();

		std::vector<Entity*> entities;
	public:
		Renderer(Renderer& other) = delete;
		~Renderer() = delete;
		void operator=(const Renderer&) = delete;


		static Renderer* getInstance();
		
		void AddEntity(Entity* entity);

		void Init();
		glm::mat4 CalculateMVPMatrix(glm::mat4 model);
		void Render();
		void Draw();
	};
}