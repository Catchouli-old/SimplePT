#include "app/SimplePT.h"

#include <sstream>

namespace pt
{
    void SimplePT::update(double deltaTime)
    {
        float dt = (float)deltaTime;

        // Update window title
        static int32_t fps = -1;

        if (getFPS() != fps)
        {
            // Update FPS
            fps = getFPS();

            // Update title
            std::stringstream ss;
            ss << "SimplePT [ FPS: " << fps << " ]";

            glfwSetWindowTitle(mWindow, ss.str().c_str());
        }

        // Input updates
        // Capture mouse on click
        if (glfwGetMouseButton(mWindow, GLFW_MOUSE_BUTTON_LEFT))
        {
            glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        }

        // Camera movement
        mCamera.update(dt);
    }
}