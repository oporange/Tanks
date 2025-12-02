#pragma once


namespace Maths
{ 
	const float PI = 3.14159265358979323846f;

	float RandomSignWave(int randx, int randy, int x, int y)
	{
		float Rx = (randx % 10) / 0.03f;
		float Ry = (randy % 100) / 10.0f;

		if (Rx == 0) { Rx = 0.1f; }
		if (Ry == 0) { Ry = 0.1f; }

		float randWidth = (randx % 5) / Rx;
		float randHeight = (randx % 100) / Ry;


		return sin((x)*randWidth) * randHeight;
	}

	Vector2 MinusVector2(Vector2 a, Vector2 b)
	{
		Vector2 out;
		out.x = a.x - b.x;
		out.y = a.y - b.y;

		return out;
	}

	float DotProduct(Vector2 a, Vector2 b)
	{
		float out;
		out = a.x * b.x + a.y * b.y;
		return out;
	}

	Vector2 ScaleVector(Vector2 a, float scale)
	{
		Vector2 out;
		out.x = a.x * scale;
		out.y = a.y * scale;
		return out;

	}
	Vector2 MultiplyVectors(Vector2 a, Vector2 b)
	{
		Vector2 out;
		out.x = a.x * b.x;
		out.y = a.y * b.y;
		return out;
	}

	Vector2 rotateVector(Vector2 a, float angle)
	{
		Vector2 out;
		out.x = a.x * cos(angle) - a.y * sin(angle);
		out.y = a.x * sin(angle) + a.y * cos(angle);
		return out;
	}

	void RasteriseTriangle(Vector2 A, Vector2 B, Vector2 C, Vector2 pos)
	{

		Vector2 LineA = Maths::MinusVector2(A, B);
		Vector2 LineB = Maths::MinusVector2(B, C);
		Vector2 LineC = Maths::MinusVector2(C, A);

		LineA = Vector2{ -LineA.y, LineA.x };
		LineB = Vector2{ -LineB.y, LineB.x };
		LineC = Vector2{ -LineC.y, LineC.x };

		float xMin = fmin(A.x, fmin(B.x, C.x));
		float yMin = fmin(A.y, fmin(B.y, C.y));
		float xMax = fmax(A.x, fmax(B.x, C.x));
		float yMax = fmax(A.y, fmax(B.y, C.y));

		int xLoop = xMax - xMin;
		int yLoop = yMax - yMin;

		for (int x = 0; x < xLoop; x++) {
			for (int y = 0; y < yLoop; y++)
			{
				float SideA = Maths::DotProduct(LineA, Maths::MinusVector2(Vector2{ (float)x + xMin, (float)y + yMin }, A));
				float SideB = Maths::DotProduct(LineB, Maths::MinusVector2(Vector2{ (float)x + xMin, (float)y + yMin }, B));
				float SideC = Maths::DotProduct(LineC, Maths::MinusVector2(Vector2{ (float)x + xMin, (float)y + yMin }, C));

				if ((SideA >= 0 && SideB >= 0 && SideC >= 0) || (SideA <= 0 && SideB <= 0 && SideC <= 0))
				{
					Screen::DrawPixel(x + xMin + pos.x, y + yMin + pos.y, SDL_Color{ 255,0,0 });
				}
			}
		}
	}
}
