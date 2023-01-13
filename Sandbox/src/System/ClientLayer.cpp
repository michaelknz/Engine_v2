#include "ClientLayer.h"
#include "Renderer/SpriteComponent.h"
#include "Core/Object.h"
#include "Scripts/ScriptComponent.h"
#include "Custom/QuadScript.h"

ClientLayer::ClientLayer()
{
	Object* quad = new Object("Quad");
	quad->AddComponent<SpriteComponent>();
	quad->AddComponent<ScriptComponent>();
	quad->GetComponent<ScriptComponent>("script")->SetScript<QuadScript>();
	quad->AddToScene();
}

ClientLayer::~ClientLayer()
{

}