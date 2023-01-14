#include "ClientLayer.h"
#include "Renderer/SpriteComponent.h"
#include "Core/Object.h"
#include "Scripts/ScriptComponent.h"
#include "Custom/QuadScript.cpp"
#include "Custom/SmallQuad.cpp"

ClientLayer::ClientLayer()
{
	Object* quad = new Object("Quad");
	quad->AddComponent<SpriteComponent>();
	quad->AddComponent<ScriptComponent>();
	quad->GetComponent<ScriptComponent>("script")->SetScript<QuadScript>();
	quad->AddToScene();

	Object* sm_quad = new Object("sm");
	sm_quad->AddComponent<SpriteComponent>();
	sm_quad->AddComponent<ScriptComponent>();
	sm_quad->GetComponent<ScriptComponent>("script")->SetScript<SmallQuad>();
	sm_quad->AddToPrefab();
}

ClientLayer::~ClientLayer()
{

}