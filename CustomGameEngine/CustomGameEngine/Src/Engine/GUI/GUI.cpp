#include "GUI.h"

namespace Engine {
	void GUI::Init(GLFWwindow* window)
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();

		ImGui::StyleColorsClassic();

		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 460");
	}

	void GUI::CreateNewFrame()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void GUI::Render()
	{
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void GUI::Destroy()
	{
		ImGui_ImplGlfw_Shutdown();
		ImGui_ImplOpenGL3_Shutdown();
		ImGui::DestroyContext();
	}
}
