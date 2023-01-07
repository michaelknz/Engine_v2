#include "ClientLayer.h"
#include "Custom/Quad.h"

ClientLayer::ClientLayer()
{
	Quad* quad = new Quad;
	quad->AddToScene();
}

ClientLayer::~ClientLayer()
{

}