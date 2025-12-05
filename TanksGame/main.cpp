
#include "iostream"
#include "vector"
#include "SDL.h"
#include "stdlib.h"

#include "Data.h"
#include "Screen.h"
#include "Maths.h"
#include "Terrain.h"
#include "Explosion.h"
#include "Tank.h"
#include "Input.h"

#undef main

int main()
{
	Screen::Init();

	Terrain::Generate(5);
	Terrain::Render();

	Tank playerTank;
	playerTank.Init();
	playerTank.Position = { 200, 400 };

	while (Running)
	{
		Input::ProcessInput();

		SDL_SetRenderDrawColor(Screen::renderer, 0, 0, 0, 0);
		SDL_RenderClear(Screen::renderer);

		Terrain::Draw();
		//std::cout << "Drawing Frame" << std::endl;

		playerTank.Render();

		SDL_RenderPresent(Screen::renderer);
	}

	return 0;
}