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
		VertexBufferObject(IndexBufferObject ibo, const void* data, unsigned int size);
		~VertexBufferObject();

		void Bind();
		void Unbind();

		void Draw();
	};
}

