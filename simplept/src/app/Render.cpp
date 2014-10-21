#include "app/SimplePT.h"

#include <gltypes/GLTexture2D.h>
#include <gltypes/GLShaderProgram.h>
#include <maths/Colour.h>
#include <rendering/Vertex.h>

#include <algorithm>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace pt
{
    void SimplePT::render()
    {
        // Render colour buffer using OpenGL
        // Clear screen to black
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Render full screen quad
        // Quad vertices
        static rend::Vertex quad[] =
        {
            /* position                 normal       texture coordinates */
            { { -1.0f, -1.0f, 0.0f },   glm::vec3(),    { 0.0f, 0.0f } },
            { {  1.0f, -1.0f, 0.0f },   glm::vec3(),    { 1.0f, 0.0f } },
            { {  1.0f,  1.0f, 0.0f },   glm::vec3(),    { 1.0f, 1.0f } },
            { {  -1.0f, 1.0f, 0.0f },   glm::vec3(),    { 0.0f, 1.0f } }
        };

        // Rendering shader
        static rend::GLShaderProgram shader("shaders/simplept.vs.glsl", "shaders/simplept.fs.glsl");
        assert(shader.isValid());

        // Set up render state
        // Activate shader
        shader.bind();

        // Set uniforms
        static int frame = 0;
        frame++;

        shader.setUniformVector("in_position", mCamera.getPosition());
        shader.setUniformMatrix("in_rotation", glm::toMat4(mCamera.getRotation()));
        shader.setUniformFloat("in_aspect", (float)mHeight / (float)mWidth);
        shader.setUniformFloat("in_time", (float)glfwGetTime());
        shader.setUniformInt("in_frame", frame);

        // Set vertex attribute location
        quad[0].bindPosition(shader, "in_vertex_position");

        // Render quad
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    }
}