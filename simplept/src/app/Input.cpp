#include "app/SimplePT.h"

#include <FreeImage.h>
#include <algorithm>

namespace pt
{
    /* The resize callback (responsible for updating opengl viewport) */
    void SimplePT::resizeCallback(GLFWwindow* window, int width, int height)
    {
        // Get application pointer
        SimplePT* app = static_cast<SimplePT*>(glfwGetWindowUserPointer(window));

        // Resize opengl viewport
        glViewport(0, 0, width, height);

        // Store width and height
        app->mWidth = width;
        app->mHeight = height;
    }
}