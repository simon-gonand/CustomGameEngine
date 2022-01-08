#include "IndexBufferObject.h"

namespace Engine {
	IndexBufferObject::IndexBufferObject(const unsigned int* data, unsigned int count): count(count)
	{
		glGenBuffers(1, &id);
		Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
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