#include "application.h"
#include <SDL/SDL.h>
#include <SDL/SDL_syswm.h>
#include <bgfx/platform.h>
#include <iostream>

namespace Game
{

	static SDL_Window* handle;

	void Application::run()
	{
		handle = SDL_CreateWindow("game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);

		SDL_SysWMinfo wmi;
		SDL_VERSION(&wmi.version);
		if (!SDL_GetWindowWMInfo(handle, &wmi))
		{
			throw std::runtime_error("ERROR : SDL_GetWindowWMInfo");
		}

		bgfx::PlatformData pd = {};
		pd.nwh = wmi.info.win.window;
		bgfx::setPlatformData(pd);

		bgfx::init();

		init();

		bool exit = false;
		SDL_Event event;
		while (!exit)
		{
			
			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
				case SDL_QUIT:
					exit = true;
					break;
				default:
					break;
				}
			}
			
			bgfx::setViewRect(0, 0, 0, 1280, 720);
			bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x303050ff);
			bgfx::touch(0);
			
			bgfx::frame();
		}

		bgfx::shutdown();

		SDL_DestroyWindow(handle);
		SDL_Quit();
	}
}