#include "IndexBufferObject.h"

namespace Engine {
	IndexBufferObject::IndexBufferObject(const unsigned int* data, unsigned int size)
	{
		glGenBuffers(1, &id);
		Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
		count = size / sizeof(unsigned int);
	}

	IndexBufferObject::~IndexBufferObject()
	{
	}

	void IndexBufferObject::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	}

	void IndexBufferObject::Unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	unsigned int IndexBufferObject::GetCount() const
	{
		return count;
	}
}