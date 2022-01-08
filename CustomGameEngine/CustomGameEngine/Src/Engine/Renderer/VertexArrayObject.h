#pragma once

#include <vector>

#include "VertexBufferObject.h"

namespace Engine {
	class VertexArrayObject
	{
	private:
		unsigned int id;
		std::vector<std::shared_ptr<VertexBufferObject>> VBOs;

	public:
		VertexArrayObject();
		~VertexArrayObject();

		void AddBuffer(VertexBufferObject& buffer);
		void Bind();
		void Unbind();

		void Draw();
	};
}