#pragma once

#include "../Logger/Logger.h"
#include "VertexArrayObject.h"

namespace Engine {
	class Renderer
	{
	private:
		static Renderer* _instance;

		Renderer();

		std::vector<std::shared_ptr<VertexArrayObject>> VAOs;
	public:
		Renderer(Renderer& other) = delete;
		~Renderer() = delete;
		void operator=(const Renderer&) = delete;


		static Renderer* getInstance();
		
		void AddVertexArray(VertexArrayObject& VAO);

		void Init();
		void CalculateMVPMatrix();
		void Render();
		void Draw();
	};
}