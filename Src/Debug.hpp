////////////////////
// FILE: Debug.hpp //
////////////////////

//////////////
// INCLUDES //
////////////// 
#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

inline void glCheckError(const char *stmt, const char *fname, int line)
{
    GLenum err;
    while ((err = glGetError()) != GL_NO_ERROR)
    {
        std::cerr << "OpenGL error " << err << " at " << fname << ":" << line
                  << " for " << stmt << std::endl;
    }
}

#define GL_CHECK(stmt)                           \
    do                                           \
    {                                            \
        stmt;                                    \
        glCheckError(#stmt, __FILE__, __LINE__); \
    } while (0)

#endif