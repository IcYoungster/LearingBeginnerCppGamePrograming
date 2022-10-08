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

void Game::UpdateModel()//任务1：将逻辑部分和绘图部分分离
{
	//代表这个准心的基线位置,为了防止其画到当前屏幕外，最小值应为5

	//任务3：将每帧增加的速度改为每秒增加的速度，需要控制速度增加只在第一帧，之后59帧（以刷新率60为例）不改变变量值

	//程序原理：先判断是否按下按键，若按下，再判断是否被控制，如果被抑制了那就什么都不做，直到松开按键，重置inhibitUp的值为false
	//第一次进入程序会先执行inhibitUp的else模块，之后inhibitUp变为true，那么直到松开按键之前就都不做任何操作
	//于是实现了按一次键加一次速度
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (inhibitUp)
		{
		}
		else
		{
			vy = vy - a;
			inhibitUp = true;
			//y = y - pmove;
		}
	}
	else {
		inhibitUp = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (inhibitDown)
		{
		}
		else
		{
			vy = vy + a;
			inhibitDown = true;
			//y = y + pmove;
		}
	}
	else {
		inhibitDown = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (inhibitLeft)
		{
		}
		else
		{
			vx = vx - a;
			inhibitLeft = true;
			//x = x - pmove;
		}
	}
	else {
		inhibitLeft = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (inhibitRight)
		{
		}
		else
		{
			vx = vx + a;
			inhibitRight = true;
			//x = x + pmove;
		}
	}
	else {
		inhibitRight = false;
	}
	//给x加上加速度（大小为上面设置的值）
	x = x + vx;
	y = y + vy;
	if (wnd.kbd.KeyIsPressed(VK_SHIFT))
	{
		R = R - 255;
	}
	ShapeIsChanged = wnd.kbd.KeyIsPressed(VK_CONTROL);
}

void Game::ComposeFrame()
{
	if (ShapeIsChanged)//换个形状
	{
		gfx.PutPixel(x - 5, y, R, 255, 255);
		gfx.PutPixel(x - 4, y, R, 255, 255);
		gfx.PutPixel(x - 3, y, R, 255, 255);
		gfx.PutPixel(x - 2, y, R, 255, 255);
		gfx.PutPixel(x - 1, y, R, 255, 255);
		gfx.PutPixel(x, y, R, 255, 255);
		//
		gfx.PutPixel(x, y - 5, R, 255, 255);
		gfx.PutPixel(x, y - 4, R, 255, 255);
		gfx.PutPixel(x, y - 3, R, 255, 255);
		gfx.PutPixel(x, y - 2, R, 255, 255);
		gfx.PutPixel(x, y - 1, R, 255, 255);
		gfx.PutPixel(x, y, R, 255, 255);
	}
	else//默认形状
	{
		gfx.PutPixel(x - 5, y, R, 255, 255);
		gfx.PutPixel(x - 4, y, R, 255, 255);
		gfx.PutPixel(x - 3, y, R, 255, 255);
		gfx.PutPixel(x + 3, y, R, 255, 255);
		gfx.PutPixel(x + 4, y, R, 255, 255);
		gfx.PutPixel(x + 5, y, R, 255, 255);
		//
		gfx.PutPixel(x, y - 5, R, 255, 255);
		gfx.PutPixel(x, y - 4, R, 255, 255);
		gfx.PutPixel(x, y - 3, R, 255, 255);
		gfx.PutPixel(x, y + 3, R, 255, 255);
		gfx.PutPixel(x, y + 4, R, 255, 255);
		gfx.PutPixel(x, y + 5, R, 255, 255);
	}
}