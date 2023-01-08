# version 450

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 UV_coords;

out vec2 Coords;
uniform mat4 mvp;

void main() {
	gl_Position = mvp * vec4(position, 1.0);
	Coords = UV_coords;
}