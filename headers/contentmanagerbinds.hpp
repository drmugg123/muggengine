#ifndef CONTENTMANAGERBINDS_HPP
#define CONTENTMANAGERBINDS_HPP

#include "contentmanager.hpp"

#include <lua.hpp>
#include <iostream>
#include <string>
#include <memory>

#include "texture2dbinds.hpp"
#include "shaderbinds.hpp"
#include "shaderprogrambinds.hpp"
#include "meshbinds.hpp"

namespace mugg {
    namespace binds {
        static const char* ContentManagerName = "ContentManager";
       
        mugg::core::ContentManager* checkContentManager(lua_State* L, int n) {
            return *(mugg::core::ContentManager**)luaL_checkudata(L, n, ContentManagerName);
        }

        int contentManagerCreateTexture2D(lua_State* L) {
            mugg::core::ContentManager* mgr = checkContentManager(L, 1);

            std::string path = lua_tostring(L, 2);
            
            bool mipmaps = false;

            if(lua_isboolean(L, 3))
                mipmaps = lua_toboolean(L, 3);
            else {
                luaL_error(L, "Second argument to metatable ContentManager:load_texture2d() wasn't a boolean.\n");
            }

            mugg::graphics::Texture2D** texture = (mugg::graphics::Texture2D**)lua_newuserdata(L, sizeof(mugg::graphics::Texture2D*));
            *texture = mgr->CreateTexture2D(path, mipmaps);

            luaL_getmetatable(L, Texture2DName);
            lua_setmetatable(L, -2);
            
            return 1;
        }

        int contentManagerCreateShader(lua_State* L) {
            mugg::core::ContentManager* mgr = checkContentManager(L, 1);

            mugg::graphics::ShaderType type = (mugg::graphics::ShaderType)luaL_checkoption(L, 2, NULL, mugg::graphics::ShaderTypeString);
            std::string path = lua_tostring(L, 3);

            mugg::graphics::Shader** shader = (mugg::graphics::Shader**)lua_newuserdata(L, sizeof(mugg::graphics::Shader*));
            *shader = mgr->CreateShader(type, path);
        
            luaL_getmetatable(L, ShaderName);
            lua_setmetatable(L, -2);

            return 1;
        }

        int contentManagerCreateShaderProgram(lua_State* L) {
            mugg::core::ContentManager* mgr = checkContentManager(L, 1);

            mugg::graphics::ShaderProgram** program = (mugg::graphics::ShaderProgram**)lua_newuserdata(L, sizeof(mugg::graphics::ShaderProgram*));
            *program = mgr->CreateShaderProgram();

            luaL_getmetatable(L, ShaderProgramName);
            lua_setmetatable(L, -2);

            return 1;
        }

        int contentManagerCreateMesh(lua_State* L) {
            mugg::core::ContentManager* mgr = checkContentManager(L, 1);

            const char* path = luaL_checkstring(L, 2);

            mugg::graphics::Mesh** mesh = (mugg::graphics::Mesh**)lua_newuserdata(L, sizeof(mugg::graphics::Mesh*));
            *mesh = mgr->CreateMesh(path);

            luaL_getmetatable(L, MeshName);
            lua_setmetatable(L, -2);

            return 1;
        }

        int contentManagerGetMaxTextureSize(lua_State* L) {
            mugg::core::ContentManager* mgr = checkContentManager(L, 1);

            lua_pushnumber(L, mgr->GetMaxTextureSize());

            return 1;
        }

        luaL_Reg contentManagerFuncs[] = {
            {"create_texture2d", contentManagerCreateTexture2D},
            {"create_shader", contentManagerCreateShader},
            {"create_shaderprogram", contentManagerCreateShaderProgram},
            {"create_mesh", contentManagerCreateMesh},

            {"get_max_texture_size", contentManagerGetMaxTextureSize},

            {NULL, NULL},
        };
    }
}

#endif
