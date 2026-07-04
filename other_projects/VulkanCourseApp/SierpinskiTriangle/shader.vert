#version 450

layout(location = 0) in vec2 position;

void main() { //this main function is executed once per each vertex we have
	gl_Position = vec4(position, 0.0, 1.0);
}