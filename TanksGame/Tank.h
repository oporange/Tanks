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
		Position.x += 0.08f;

		Vector2 p1 = Coords[2];
		Vector2 p2 = Coords[3];

		int P1_TerrainHeight = Position.y - p1.y;
		while (Terrain::TerrainBuffer[(int)(p1.x + Position.x)][P1_TerrainHeight] == 0)
		{
			P1_TerrainHeight++;
		}
		int P2_TerrainHeight = Position.y - p2.y;
		while (Terrain::TerrainBuffer[(int)(p2.x + Position.x)][P2_TerrainHeight] == 0)
		{
			P2_TerrainHeight++;
		}

		Position.y = (float)(P1_TerrainHeight + P2_TerrainHeight) / 2.0f - 10.0f;

		angle = atan2f((float)(P2_TerrainHeight - P1_TerrainHeight), (p2.x - p1.x));
		angle += Maths::PI / 4;

		Vector2 RotatedCoords[4] = {};

		for (int i = 0; i < 4; i++)
		{
			RotatedCoords[i] = Maths::rotateVector(Coords[i], angle - Maths::PI / 4);
		}

		Maths::RasteriseTriangle(RotatedCoords[0], RotatedCoords[1], RotatedCoords[2], Position);
		Maths::RasteriseTriangle(RotatedCoords[0], RotatedCoords[2], RotatedCoords[3], Position);
	}

};