#include "Quad.h"
#include "Renderer/SpriteComponent.h"

Quad::Quad()
	:Object("Quad")
{
	AddComponent<SpriteComponent>("Sprite");
}

Quad::~Quad()
{

}