#version 400

in vec4 color;

out vec4 frag_colour;

void main () {
	frag_colour = color;
	// frag_colour = vec4(1.f);
}
