#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Engine/Logger/Logger.h"
#include "Engine/Renderer/Renderer.h"
#include "Engine/Renderer/VertexArrayObject.h"
#include "Engine/Renderer/VertexBufferObject.h"
#include "Engine/Renderer/IndexBufferObject.h"
#include "Engine/Renderer/Shader.h"

int main(void) {
	Engine::Logger::Init();
	EngineLog("Engine Logger initialized");
	DebugLog("Debug Logger initialized");

	if (!glfwInit())
	{
		EngineLog("Failed to initialize GLFW");
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // On veut OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Pour rendre MacOS heureux ; ne devrait pas être nécessaire
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // On ne veut pas l'ancien OpenGL

	GLFWwindow* window = glfwCreateWindow(1024, 768, "Test", NULL, NULL);
	glfwMakeContextCurrent(window);
	glewExperimental = true;

	if (glewInit() != GLEW_OK) {
		EngineLog("Failed to initialize GLEW");
		return -1;
	}

	Engine::Renderer::getInstance()->Init();

	//Triangle test
	static const GLfloat g_vertex_buffer_data[] = {
	   -1.0f, -1.0f, 0.0f,
	   1.0f, -1.0f, 0.0f,
	   0.0f,  1.0f, 0.0f,
	};

	static const unsigned int index[] = { 0,1,2 };

	Engine::VertexArrayObject vao = Engine::VertexArrayObject();
	Engine::IndexBufferObject ibo = Engine::IndexBufferObject(index, 3);
	Engine::VertexBufferObject vbo = Engine::VertexBufferObject(ibo, g_vertex_buffer_data, sizeof(g_vertex_buffer_data));
	vao.AddBuffer(vbo);

	Engine::Renderer::getInstance()->AddVertexArray(vao);

	Engine::Shader shader = Engine::Shader("Src/Shaders/vertShader.vert", "Src/Shaders/fragShader.frag");

	while (glfwWindowShouldClose(window) == 0) {
		glfwSwapBuffers(window);
		glfwPollEvents();

		shader.Bind();
		Engine::Renderer::getInstance()->Render();
		Engine::Renderer::getInstance()->Draw();
		shader.Unbind();
		vao.Unbind();
	}

	glfwTerminate();

	return 0;
}