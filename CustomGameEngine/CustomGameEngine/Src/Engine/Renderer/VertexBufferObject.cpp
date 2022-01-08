#include "VertexBufferObject.h"

namespace Engine {
	VertexBufferObject::VertexBufferObject(IndexBufferObject ibo, const void* data, unsigned int size)
	{
		IBO = std::make_shared<IndexBufferObject>(ibo);

		glGenBuffers(1, &id);
		glBindBuffer(GL_ARRAY_BUFFER, id);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}

	VertexBufferObject::~VertexBufferObject()
	{
	}

	void VertexBufferObject::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, id);
		IBO->Bind();
	}

	void VertexBufferObject::Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		IBO->Unbind();
	}

	void VertexBufferObject::Draw() {
		glDrawElements(GL_TRIANGLES, IBO->GetCount(), GL_UNSIGNED_INT, (void*)0);
	}
}