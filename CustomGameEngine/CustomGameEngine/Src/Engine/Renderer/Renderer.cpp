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

    void Renderer::AddVertexArray(VertexArrayObject& VAO)
    {
        DebugLog(VAOs.size());
        VAOs.push_back(std::make_shared<VertexArrayObject>(VAO));
        DebugLog(VAOs.size());
    }

    void Renderer::Init()
    {
        // Dark blue background
        glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

        // Enable depth test
        //glEnable(GL_DEPTH_TEST);
        // Accept fragment if it closer to the camera than the former one
        //glDepthFunc(GL_LESS);

        EngineLog("Renderer Initialized");
    }

    void Renderer::CalculateMVPMatrix()
    {
        // TODO
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