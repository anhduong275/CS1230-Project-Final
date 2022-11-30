#pragma once
#ifndef DEBUG_H
#define DEBUG_H

#include <GL/glew.h>
#include <iostream>

namespace Debug
{
    // TASK 2: Add file name and line number parameters
    inline void glErrorCheck(const char *fileName, int lineNumber)
    {
        GLenum error = glGetError();
        while (error != GL_NO_ERROR)
        {
            // Task 2: Edit this print statement to be more descriptive
            std::cout << error << " in file " << fileName << " at line " << lineNumber << std::endl;
            error = glGetError();
        }
    }

// TASK 3: Add a preprocessor directive to automate the writing of this function
#define glErrorCheck() glErrorCheck(__FILE__, __LINE__)
}

#endif // DEBUG_H
