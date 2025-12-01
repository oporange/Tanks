#pragma once

namespace Screen
{
	const int SCREEN_WIDTH = 1200;
	const int SCREEN_HEIGHT = 800;

	SDL_Renderer* renderer;
	SDL_Window* window;

	void Init()
	{

		SDL_Init(SDL_INIT_EVERYTHING);

		window = SDL_CreateWindow("SDL Window",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);

		renderer = SDL_CreateRenderer(window, -1, 0);

	}

	void DrawPixel(int x, int y, SDL_Color color)
	{
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawPoint(renderer, x, y);
	}

}