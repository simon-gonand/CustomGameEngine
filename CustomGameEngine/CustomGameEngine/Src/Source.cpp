#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Engine/Logger.h"

int main(void) {
	Engine::Logger::Init();
	EngineLog("Engine Logger initialized");
	DebugLog("Debug Logger initialized");

	if (!glfwInit())
	{
		std::cerr << "Failed to initialize GLFW\n" << std::endl;
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
		std::cerr << "Failed to initialize GLEW\n" << std::endl;
		return -1;
	}

	while (glfwWindowShouldClose(window) == 0) {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
}