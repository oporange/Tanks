#pragma once
#include "Terrain.h"

SDL_Event event;

namespace Input
{
	void ProcessInput()
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				Running = false;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (event.button.button == 1)
				{
					int x = 0; int y = 0;
					SDL_GetMouseState(&x, &y);
					Explosion(x, y, 50);
					std::cout << "fire" << std::endl;
				}
			}
		}
	}
}