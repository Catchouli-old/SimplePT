#version 330 core

uniform mat4 in_mvp;
uniform float in_time;

in vec3 in_vertex_position;

out vec3 vertex_pos;

void main()
{
	gl_Position = vec4(in_vertex_position, 1.0);
	vertex_pos = in_vertex_position;
}