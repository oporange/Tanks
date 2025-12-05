#pragma once
#include "iostream"


namespace Terrain
{

	int TerrainBuffer[Screen::SCREEN_WIDTH][Screen::SCREEN_HEIGHT];
	SDL_Texture* TerrainTexture;

	void ClearBuffer()
	{
		for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
			for (int y = 0; y < Screen::SCREEN_HEIGHT; y++)
			{
				TerrainBuffer[x][y] = 0;
			}
		}
	}

	void Generate(int Lacunarity) 
	{
		TerrainTexture = SDL_CreateTexture(Screen::renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,
									Screen::SCREEN_WIDTH, Screen::SCREEN_HEIGHT);
		srand(time(0));

		std::vector<float> rands;
		std::vector<float> heights;

		rands.resize(Lacunarity); heights.resize(Lacunarity);

		for (int i = 0; i < Lacunarity; i++)
		{
			rands[i] = rand(); heights[i] = rand();
		}

		for (int x = 0; x < Screen::SCREEN_WIDTH; x++){
			for (int y = 0; y < Screen::SCREEN_HEIGHT; y++)
			{

				float height = 0;

				for (int i = 0; i < Lacunarity; i++)
				{
					height += Maths::RandomSignWave(rands[i], heights[i], x, y) / ((i + 1)/1.8);
				}
				height += 600;

				if (height > 790) { height = 790; }

				if (y > height) {
					TerrainBuffer[x][y] = 1;
				}
				


			}}

		SDL_SetRenderTarget(Screen::renderer, TerrainTexture);

		for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
			for (int y = 0; y < Screen::SCREEN_HEIGHT; y++)
			{
				if (TerrainBuffer[x][y] == 1) {
					Screen::DrawPixel(x, y, { 15, 217, 252, 255 });
				}
			}
		}
		SDL_SetRenderTarget(Screen::renderer, NULL);
	}

	void Draw()
	{
		SDL_Rect destRect = { 0, 0, Screen::SCREEN_WIDTH, Screen::SCREEN_HEIGHT };
		SDL_RenderCopy(Screen::renderer, TerrainTexture, NULL, &destRect);
		std::cout << SDL_GetError() << std::endl;
	}



}