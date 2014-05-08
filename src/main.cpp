#include <string>
#include <vector>
#include <ctime>

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "filehandler.hpp"
#include "log.hpp"
#include "file.hpp"
#include "shader.hpp"
#include "defs.hpp"
#include "window.hpp"
#include "shaderprogram.hpp"
#include "engine.hpp"

int main() {
    
    mugg::Window window;
    mugg::Context context;
    mugg::Engine engine(context);

    mugg::ShaderProgram shaderProgram;
    shaderProgram.AddShader("data/shaders/vertex.glsl", mugg::VERTEX_SHADER);
    shaderProgram.AddShader("data/shaders/fragment.glsl", mugg::FRAGMENT_SHADER);

    window.Create("MuggEngine Window", glm::vec2(800, 600), glm::vec2(0, 0));

    while(window.IsOpen()) {
        engine.Render();

        window.SwapBuffers();
        glfwPollEvents();
    }

	return 0;
}
