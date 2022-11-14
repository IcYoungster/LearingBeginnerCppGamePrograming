#include"graphics.h"
#include"Dude.h"
#include"Keyboard.h"
void Dude::ClampDude()
{
	const int bottom = y + Height;
	const int right = x + Width;
	if (y < 0)
		y = 0;
	else if (bottom >= Graphics::ScreenHeight)
		y = Graphics::ScreenHeight - 1 - Height;
	if (x < 0)
		x = 0;
	else if (right >= Graphics::ScreenWidth)
		x = Graphics::ScreenWidth - 1 - Width;
}
