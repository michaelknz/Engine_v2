# version 450

in vec2 Coords;
uniform sampler2D Texture;
out vec4 FragColor;

void main() {
	vec2 cord=vec2(Coords.x,1.0 - Coords.y);
    FragColor=texture(Texture,cord);
}