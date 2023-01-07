#include "Engine.h"
#include "ClientLayer.h"

int main()
{
	MainLoop main_loop(800, 600, "Engine");
	ClientLayer layer;
	main_loop.Loop();
	return 0;
	
}