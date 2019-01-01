#include <Windows.h>
#include "application.h"

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, int nCmdShow)
{
	
	Game::Application app;
	app.run();

	return 0;
}