#ifndef SIMPLEPT_SIMPLEPT_H
#define SIMPLEPT_SIMPLEPT_H

#include <memory>

#include <app/Application.h>
#include <rendering/FPSCamera.h>

namespace pt
{
    class SimplePT
        : public rend::Application
    {
    public:

        /* Default constructor for application */
        SimplePT();

        /* Update function */
        void update(double dt) override;

        /* Rendering function */
        void render() override;

    private:
        
        /* The resize callback (responsible for updating opengl viewport) */
        static void resizeCallback(GLFWwindow* window, int width, int height);

        /* The camera from which to render */
        rend::FPSCamera mCamera;

        /* Dimensions of the window */
        int mWidth, mHeight;

    };
}

#endif /* SIMPLEPT_SIMPLEPT_H */