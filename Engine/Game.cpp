/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
}

void Game::ComposeFrame()
{
	//代表这个准心的基线位置,为了防止其画到当前屏幕外，最小值应为5
	const int x = 400;
	const int y = 300;
	const int pmove = 200;
	int px = x, py = y;
	int R = 255;

	const bool cond_ccolor = wnd.kbd.KeyIsPressed(VK_SHIFT);
	const bool cond_cshape = wnd.kbd.KeyIsPressed(VK_CONTROL);
	const bool cond_up = wnd.kbd.KeyIsPressed(VK_UP);
	const bool cond_down = wnd.kbd.KeyIsPressed(VK_DOWN);
	const bool cond_left = wnd.kbd.KeyIsPressed(VK_LEFT);
	const bool cond_right = wnd.kbd.KeyIsPressed(VK_RIGHT);
	if (cond_up)
	{
		py = y - pmove;
	}
	if (cond_down)
	{
		py = y + pmove;
	}
	if (cond_left)
	{
		px = x - pmove;
	}
	if (cond_right)
	{
		px = x + pmove;
	}
	if (cond_ccolor)
	{
		R = R - 255;
	}
	if (cond_cshape)//形状1
	{
		gfx.PutPixel(px - 5, py, R, 255, 255);
		gfx.PutPixel(px - 4, py, R, 255, 255);
		gfx.PutPixel(px - 3, py, R, 255, 255);
		gfx.PutPixel(px + 3, py, R, 255, 255);
		gfx.PutPixel(px + 4, py, R, 255, 255);
		gfx.PutPixel(px + 5, py, R, 255, 255);
		//
		gfx.PutPixel(px, py - 5, R, 255, 255);
		gfx.PutPixel(px, py - 4, R, 255, 255);
		gfx.PutPixel(px, py - 3, R, 255, 255);
		gfx.PutPixel(px, py + 3, R, 255, 255);
		gfx.PutPixel(px, py + 4, R, 255, 255);
		gfx.PutPixel(px, py + 5, R, 255, 255);
	}
	else//另一个形状
	{
		gfx.PutPixel(px - 5, py, R, 255, 255);
		gfx.PutPixel(px - 4, py, R, 255, 255);
		gfx.PutPixel(px - 3, py, R, 255, 255);
		gfx.PutPixel(px - 2, py, R, 255, 255);
		gfx.PutPixel(px - 1, py, R, 255, 255);
		gfx.PutPixel(px, py, R, 255, 255);
		//
		gfx.PutPixel(px, py - 5, R, 255, 255);
		gfx.PutPixel(px, py - 4, R, 255, 255);
		gfx.PutPixel(px, py - 3, R, 255, 255);
		gfx.PutPixel(px, py - 2, R, 255, 255);
		gfx.PutPixel(px, py - 1, R, 255, 255);
		gfx.PutPixel(px, py, R, 255, 255);
	}
}