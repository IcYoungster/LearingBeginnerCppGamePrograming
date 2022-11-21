#include "Rect.h"

void Rect::Init(int ini_x, int ini_y)
{
	x = ini_x;
	y = ini_y;
}

void Rect::Draw(Graphics& gfx) const
{
	for (int i = x; i < x+width; i++)
	{
		for (int j = y; j < y+height; j++)
		{
			gfx.PutPixel(i,j,Colors::Red);
		}
	}
}

void Rect::CollidingTest(const Dude& dude)
{
	const int dright = dude.getX() + dude.getWidth();
	const int dbottom = dude.getY() + dude.getHeight();
	const int rright = x + width;//因为x是poo的x值
	const int rbottom = y + height;
	if (x <= dright &&
		dude.getX() <= rright &&
		y <= dbottom &&
		dude.getY() <= rbottom)
	{
		IsEaten = true;
	}
}

bool Rect::IsEat()
{
	return IsEaten;
}

void Rect::SetEat(bool var)
{
	IsEaten = var;
}
