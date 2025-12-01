#pragma once

class Tank
{
	Vector2 Coords[4] = { {-1, -0.5}, {1, -0.5},  {1, 0.5}, {-1, 0.5} };

public:
	Vector2 Position;

	void Init()
	{
		for (int i = 0; i < 4; i++)
		{
			Coords[i] = Maths::ScaleVector(Coords[i], 20.0f);
		}
	}

	void Render()
	{
		for (int i = 0; i < 4; i++)
		{
			Coords[i] = Maths::rotateVector(Coords[i], 0.05f);
		}

		Screen::DrawPixel(Coords[0].x + Position.x, Coords[0].y + Position.y, SDL_Color{0,255,0});
		Screen::DrawPixel(Coords[1].x + Position.x, Coords[1].y + Position.y, SDL_Color{0,255,0});
		Screen::DrawPixel(Coords[2].x + Position.x, Coords[2].y + Position.y, SDL_Color{0,255,0});
		Screen::DrawPixel(Coords[3].x + Position.x, Coords[3].y + Position.y, SDL_Color{0,255,0});

		Maths::RasteriseTriangle(Coords[0], Coords[1], Coords[2], Position);
		Maths::RasteriseTriangle(Coords[0], Coords[2], Coords[3], Position);
	}

};