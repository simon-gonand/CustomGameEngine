#include "Renderer.h"

namespace Engine {
    Renderer* Renderer::_instance = nullptr;

    Renderer::Renderer()
    {
    }

    Renderer* Renderer::getInstance()
    {
        if (_instance == nullptr) 
            _instance = new Renderer();
        return _instance;
    }

    void Renderer::AddVertexArray(std::shared_ptr<VertexArrayObject> VAO)
    {
        VAOs.push_back(VAO);
    }

    void Renderer::Init()
    {
        // Dark blue background
        glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

        // Enable depth test
        glEnable(GL_DEPTH_TEST);
        // Accept fragment if it closer to the camera than the former one
        glDepthFunc(GL_LESS);

        EngineLog("Renderer Initialized");
    }

    glm::mat4 Renderer::CalculateMVPMatrix()
    {
        glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
        glm::mat4 View = glm::lookAt(
            glm::vec3(4, 3, -3), // Camera is at (4,3,-3), in World Space
            glm::vec3(0, 0, 0), // and looks at the origin
            glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
        );
        glm::mat4 Model = glm::mat4(1.0f);
        return Projection * View * Model;
    }

    void Renderer::Render()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // TODO
    }

    void Renderer::Draw()
    {
        for (std::shared_ptr<VertexArrayObject> VAO : VAOs) {
            VAO->Bind();
            VAO->Draw();
        }
    }
}