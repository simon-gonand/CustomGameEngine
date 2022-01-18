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


		static Renderer* GetInstance();
		
		void AddEntity(Entity* entity);
		std::vector<Entity*> GetEntities() const;

		void Init();
		glm::mat4 CalculateMVPMatrix(glm::mat4 model);
		void Render();
		void Update(float tick);
		void Draw();
	};
}