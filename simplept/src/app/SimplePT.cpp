#include "app/SimplePT.h"

#include <ctime>
#include <random>

namespace pt
{
    SimplePT::SimplePT()
        : Application(800, 600, "SimplePT"),
        mCamera(mWindow, 1.0f, 10.0f)
    {
        // Centre mouse cursor by default
        glfwSetCursorPos(mWindow, getWidth() * 0.5, getHeight() * 0.5);

        // Reset camera to make sure cursor pos set didn't mess things up
        mCamera.update(0);
        mCamera.setPosition(glm::vec3(0, 0, 4.9f));
        mCamera.setComponentRotation(0, 0);

        // Store application pointer in glfw window (for static callbacks)
        glfwSetWindowUserPointer(mWindow, this);

        // Set up resize function
        glfwSetWindowSizeCallback(mWindow, resizeCallback);

        // Initialise viewport and colour buffer
        resizeCallback(mWindow, getWidth(), getHeight());
    }
}