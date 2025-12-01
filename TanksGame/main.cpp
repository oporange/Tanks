
#include "iostream"
#include "vector"
#include "SDL.h"
#include "stdlib.h"

#include "Data.h"
#include "Screen.h"
#include "Maths.h"
#include "Terrain.h"

#undef main

int main()
{
	Screen::Init();

	Terrain::Generate(5);


	while (Running)
	{
		SDL_SetRenderDrawColor(Screen::renderer, 0, 0, 0, 0);
		SDL_RenderClear(Screen::renderer);

		Terrain::Draw();
		//std::cout << "Drawing Frame" << std::endl;

		SDL_RenderPresent(Screen::renderer);
	}

	return 0;
}