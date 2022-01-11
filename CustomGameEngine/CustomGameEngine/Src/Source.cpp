#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Engine/Logger/Logger.h"
#include "Engine/Renderer/Renderer.h"
#include "Engine/Renderer/VertexArrayObject.h"
#include "Engine/Renderer/VertexBufferObject.h"
#include "Engine/Renderer/IndexBufferObject.h"
#include "Engine/Renderer/Shader.h"

#include "Engine/Entity.h"

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
	float bufferData[] = {
	    -1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		 1.0f, 1.0f, 1.0f,
		 1.0f, 1.0f,-1.0f,
		 1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		 1.0f,-1.0f, 1.0f
	};

	unsigned int index[] = { 
		0, 1, 2, // left face
		0, 2, 6,
		0, 1, 7, // bottom face
		0, 5, 7,
		0, 6, 4, // front face
		4, 5, 6,
		4, 5, 7, // right face
		3, 4, 5,
		3, 4, 6, // top face
		2, 3, 6,
		1, 2, 7, // back face
		2, 3, 7
	};

	/*Engine::VertexArrayObject vao = Engine::VertexArrayObject();
	Engine::IndexBufferObject ibo = Engine::IndexBufferObject(index, sizeof(index));
	Engine::VertexBufferObject vbo = Engine::VertexBufferObject(std::make_shared<Engine::IndexBufferObject>(ibo), 
		bufferData, sizeof(bufferData));
	vao.AddBuffer(std::make_shared<Engine::VertexBufferObject>(vbo));
	Engine::Renderer::getInstance()->AddVertexArray(std::make_shared<Engine::VertexArrayObject>(vao));*/

	Engine::Entity entity = Engine::Entity(bufferData, sizeof(bufferData), index, sizeof(index), "Src/Shaders/vertShader.vert", "Src/Shaders/fragShader.frag");

	//Engine::Shader shader = Engine::Shader("Src/Shaders/vertShader.vert", "Src/Shaders/fragShader.frag");
	//GLuint MatrixID = glGetUniformLocation(shader.GetId(), "MVP");

	//glm::mat4 MVP = Engine::Renderer::getInstance()->CalculateMVPMatrix();

	while (glfwWindowShouldClose(window) == 0) {
		glfwSwapBuffers(window);
		glfwPollEvents();

		//shader.Bind();
		//glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
		Engine::Renderer::getInstance()->Render();
		entity.Draw();
		//shader.Unbind();
		//vao.Unbind();
	}

	glfwTerminate();

	return 0;
}