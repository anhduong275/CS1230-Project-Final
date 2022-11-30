#version 400

// inputs
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

// uniform mat4 modelMatrix;
// uniform mat4 viewMatrix;
// uniform mat4 projMatrix;

out vec4 color;

void main () {
	// gl_Position = projMatrix * viewMatrix * modelMatrix * vec4(position, 1);
	gl_Position = vec4(position, 1.f);
	// color = vec4(1.f);
	color = vec4(normal, 1.f);
}
