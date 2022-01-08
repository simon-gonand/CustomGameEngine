#pragma once

#include <GL/glew.h>

namespace Engine {
	class IndexBufferObject
	{
	private:
		unsigned int id;
		unsigned int count;

	public:
		IndexBufferObject(const unsigned int* data, unsigned int count);
		~IndexBufferObject();

		void Bind();
		void Unbind();

		unsigned int GetCount() const;
	};
}

