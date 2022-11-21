#include "Rect.h"

Rect::Rect(int ini_x, int ini_y)
{
	x = ini_x;
	y = ini_y;
}

void Rect::Draw(Graphics& gfx) const
{
	for (int i = x; i < x+side; i++)
	{
		for (int j = y; j < y+side; j++)
		{
			gfx.PutPixel(i,j,c);
		}
	}
}

bool Rect::CollidingTest(const Dude& dude)
{
	const int dright = dude.getX() + dude.getWidth();
	const int dbottom = dude.getY() + dude.getHeight();
	const int rright = x + side;//因为x是poo的x值
	const int rbottom = y + side;
	return(x <= dright &&
		dude.getX() <= rright &&
		y <= dbottom &&
		dude.getY() <= rbottom);
}
/*重生\重新赋值*/
void Rect::Respawn(int ini_x, int ini_y)
{
	x = ini_x;
	y = ini_y;
}

void Rect::UpdateColor()
{
	if (colorIncreseing)
	{
		if (c.GetR() >= 253)
		{
			colorIncreseing = false;
		}
		else
		{
			c = Color(c.GetR() + 2, c.GetG() + 4, c.GetB() + 4);
		}
	}
	else 
	{
		if (c.GetR() <= 127)
		{
			colorIncreseing = true;
		}
		else
		{
			c = Color(c.GetR() - 2, c.GetG() - 4, c.GetB() - 4);
		}
	}
}
