#include "VertexArrayObject.h"

#include "../Logger/Logger.h"

namespace Engine {
	VertexArrayObject::VertexArrayObject()
	{
		glGenVertexArrays(1, &id);
		glBindVertexArray(id);
	}

	VertexArrayObject::~VertexArrayObject()
	{
	}

	void VertexArrayObject::AddBuffer(std::shared_ptr<VertexBufferObject> buffer)
	{
		Bind();
		buffer->Bind();
		glEnableVertexAttribArray(VBOs.size());
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		VBOs.push_back(buffer);
	}

	void VertexArrayObject::Bind()
	{
		glBindVertexArray(id);
	}

	void VertexArrayObject::Unbind()
	{
		glBindVertexArray(0);

		for (std::shared_ptr<VertexBufferObject> vbo : VBOs) {
			vbo->Unbind();
		}
	}
	void VertexArrayObject::Draw()
	{
		for (std::shared_ptr<VertexBufferObject> vbo : VBOs) {
			vbo->Bind();
			vbo->Draw();
		}
	}
}