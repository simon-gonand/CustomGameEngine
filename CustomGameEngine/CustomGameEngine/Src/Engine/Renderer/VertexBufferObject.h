#pragma once

#include <memory>

#include "IndexBufferObject.h"

namespace Engine {
	class VertexBufferObject
	{
	private:
		unsigned int id;
		std::shared_ptr<IndexBufferObject> IBO;

	public:
		VertexBufferObject(std::shared_ptr<IndexBufferObject> ibo, const float* data, unsigned int size);
		~VertexBufferObject();

		void Bind();
		void Unbind();

		void Draw();
	};
}

