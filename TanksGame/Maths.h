#pragma once


namespace Maths
{
	float RandomSignWave(int randx, int randy, int x, int y)
	{
		float Rx = (randx % 10) / 0.03f;
		float Ry = (randy % 100) / 10.0f;

		if (Rx == 0) { Rx = 0.1f; }
		if (Ry == 0) { Ry = 0.1f; }

		float randWidth = (randx % 5) / Rx;
		float randHeight = (randx % 100) / Ry;


		return sin((x) * randWidth) * randHeight;
	}



}
