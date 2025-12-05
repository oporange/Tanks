#pragma once


void Explosion(int centerX, int centerY, int radius)
{

	for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++)
		{

			if ( ( (x - centerX) * (x - centerX) + (y - centerY) * (y - centerY) ) <= radius * radius )
			{
				Terrain::TerrainBuffer[x][y] = 0;
			}
		}
	}

	Terrain::Render();

}