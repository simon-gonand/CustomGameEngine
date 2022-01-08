#pragma once

#include <string>
#include <fstream>

#include "../Logger/Logger.h"

// Shader class create with the help of the kronos wiki on Shader compilation: https://www.khronos.org/opengl/wiki/Shader_Compilation
namespace Engine {
	class Shader
	{
	private:
		unsigned int id;

		char* LoadFile(const char* fname, int& fsize);

	public:
		Shader(const char* vertSrcFile, const char* fragSrcFile);
		~Shader();

		void Bind();
		void Unbind();

		unsigned int GetId() const;
	};
}