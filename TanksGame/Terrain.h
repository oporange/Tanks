#pragma once
#include "iostream"


namespace Terrain
{

	int TerrainBuffer[Screen::SCREEN_WIDTH][Screen::SCREEN_HEIGHT];


	void Generate(int Lacunarity) 
	{
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

	}

	void Draw()
	{
		for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
			for (int y = 0; y < Screen::SCREEN_HEIGHT; y++)
			{
				if (TerrainBuffer[x][y] == 1) {
					Screen::DrawPixel(x, y, { 15, 217, 252, 255 });
				}
			}
		}
	}



}