#ifndef GRAPHICSDEFS_HPP
#define GRAPHICSDEFS_HPP

#include <GL/glew.h>

namespace mugg {
    namespace graphics {
        enum TextureFilter {            
            Nearest,
            Linear,
        };
        enum TextureRepeatPattern {
            Repeat,
        };
        enum ShaderType {
            VertexShader,
            FragmentShader,
            GeometryShader,
        };

        static const char* ShaderTypeString[] = {
            "VertexShader",
            "FragmentShader",
            "GeometryShader",
            NULL
        };
    }
}

#endif
