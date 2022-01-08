#include "Shader.h"

#include <GL/glew.h>

namespace Engine {
	Shader::Shader(const char* vertSrcFile, const char* fragSrcFile)
	{
		GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);

		GLint vlen;
		GLint flen;
		char* source = LoadFile(vertSrcFile, vlen);
		char* fragment = LoadFile(fragSrcFile, flen);

		glShaderSource(vertShader, 1, &source, &vlen);
		glShaderSource(fragShader, 1, &fragment, &flen);

		GLint compiled = 0;
		glCompileShader(vertShader);
		glGetShaderiv(vertShader, GL_COMPILE_STATUS, &compiled);
		if (!compiled) {
			GLint maxLength = 0;
			glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(vertShader, maxLength, &maxLength, &infoLog[0]);

			// We don't need the shader anymore.
			glDeleteShader(vertShader);

			EngineLogError("Vertex shader compilation error");
			EngineLogError("{}", infoLog.data());

			return;
		}

		glCompileShader(fragShader);
		glGetShaderiv(fragShader, GL_COMPILE_STATUS, &compiled);
		if (!compiled) {
			GLint maxLength = 0;
			glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(fragShader, maxLength, &maxLength, &infoLog[0]);

			// We don't need the shader anymore.
			glDeleteShader(fragShader);

			EngineLogError("Fragment shader compilation error");
			EngineLogError("{}", infoLog.data());

			return;
		}

		id = glCreateProgram();

		glAttachShader(id, vertShader);
		glAttachShader(id, fragShader);

		glLinkProgram(id);
		GLint isLinked = 0;
		glGetProgramiv(id, GL_LINK_STATUS, (int*)&isLinked);
		if (isLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(id, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(id, maxLength, &maxLength, &infoLog[0]);

			// We don't need the program anymore.
			glDeleteProgram(id);
			// Don't leak shaders either.
			glDeleteShader(vertShader);
			glDeleteShader(fragShader);

			EngineLogError("Program link error");
			EngineLogError("{}", infoLog.data());
			return;
		}

		glDetachShader(id, vertShader);
		glDetachShader(id, fragShader);
	}

	Shader::~Shader() 
	{
		glDeleteProgram(id);
	}

	void Shader::Bind()
	{
		glUseProgram(id);
	}

	void Shader::Unbind()
	{
		glUseProgram(0);
	}

	unsigned int Shader::GetId() const
	{
		return id;
	}

	char* Shader::LoadFile(const char* fname, int& fsize)
	{
		int size;
		char* memblock;

		// file read based on example in cplusplus.com tutorial
		// ios::ate opens file at the end
		std::ifstream file(fname, std::ios::in | std::ios::binary | std::ios::ate);
		if (file.is_open()) {
			size = (int)file.tellg(); // get location of file pointer i.e. file size
			fsize = size;
			memblock = new char[size];
			file.seekg(0, std::ios::beg);
			file.read(memblock, size);
			file.close();
			EngineLog("File {} has been loaded", fname);
		}
		else {
			EngineLogError("Unable to open file {}", fname);
			fsize = 0;
			// should ideally set a flag or use exception handling
			// so that calling function can decide what to do now
			return nullptr;
		}
		return memblock;
	}
}