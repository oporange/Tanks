#pragma once

class Tank
{
	Vector2 Coords[4] = { {-1, -0.5}, {1, -0.5},  {1, 0.5}, {-1, 0.5} };

public:
	Vector2 Position;
	float angle;

	void Init()
	{
		for (int i = 0; i < 4; i++)
		{
			Coords[i] = Maths::MultiplyVectors(Coords[i], Vector2{15.0f, 20.0f});
		}
	}

	void Render()
	{
		angle += 0.03f;
		angle = fmod(angle, Maths::PI/2);

		Vector2 PreviousRotation[4] = {};

		for (int i = 0; i < 4; i++)
		{
			PreviousRotation[i] = Maths::rotateVector(Coords[i], angle - Maths::PI/4);
		}

		Vector2 p1 = Coords[2];
		Vector2 p2 = Coords[3];

		Vector2 RotatedCoords[4] = {};

		for (int i = 0; i < 4; i++)
		{
			RotatedCoords[i] = Maths::rotateVector(Coords[i], angle - Maths::PI / 4);
		}

		Maths::RasteriseTriangle(RotatedCoords[0], RotatedCoords[1], RotatedCoords[2], Position);
		Maths::RasteriseTriangle(RotatedCoords[0], RotatedCoords[2], RotatedCoords[3], Position);

		SDL_SetRenderDrawColor(Screen::renderer, 0, 255, 0, 255);
		SDL_RenderDrawPoint(Screen::renderer, (int)(p1.x + Position.x), (int)(p1.y + Position.y));
		SDL_RenderDrawPoint(Screen::renderer, (int)(p2.x + Position.x), (int)(p2.y + Position.y));
	}

};