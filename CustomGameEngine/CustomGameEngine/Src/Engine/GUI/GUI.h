#pragma once

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

namespace Engine {
	class GUI
	{
	public:
		static void Init(GLFWwindow *window);
		static void CreateNewFrame();
		static void Render();
		static void Destroy();
	};
}