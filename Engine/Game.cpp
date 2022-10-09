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
//控制移动的box
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y_mobile = y_mobile - 1;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y_mobile = y_mobile + 1;
	}
	
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x_mobile = x_mobile - 1;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		x_mobile = x_mobile + 1;
	}

//判断碰撞，首先设定两个盒子的边框
	const int left_mobile = x_mobile - 5;
	const int right_mobile = x_mobile + 5;
	const int top_mobile = y_mobile - 5;
	const int bottom_mobile = y_mobile + 5;

	const int left_fixed = x_fixed - 5;
	const int right_fixed = x_fixed + 5;
	const int top_fixed = y_fixed - 5;
	const int bottom_fixed = y_fixed + 5;
//然后写条件,当m盒左侧小于f盒右侧，且m盒右侧大于f盒左侧，且m盒上方小于f盒下方，且m盒下方大于f盒上方时确认为碰撞
	
//也可以这样写（偷懒）：
//	Colliding = (left_mobile < right_fixed&& right_mobile > left_fixed && top_mobile < bottom_fixed&& bottom_mobile > top_fixed);

	if (left_mobile < right_fixed &&
		right_mobile > left_fixed &&
		top_mobile < bottom_fixed &&
		bottom_mobile > top_fixed)
	{
		Colliding = true;
	}else {
		Colliding = false;
	}
}

void Game::ComposeFrame()
{
	//首先绘制固定的方框
	int r_fixed = 0, g_fixed = 255, b_fixed = 0;
	//上方横向线
	gfx.PutPixel(x_fixed - 5, y_fixed + 5, r_fixed,g_fixed,b_fixed);
	gfx.PutPixel(x_fixed - 4, y_fixed + 5, r_fixed,g_fixed,b_fixed);
	gfx.PutPixel(x_fixed - 3, y_fixed + 5, r_fixed,g_fixed,b_fixed);
	gfx.PutPixel(x_fixed + 3, y_fixed + 5, r_fixed,g_fixed,b_fixed);
	gfx.PutPixel(x_fixed + 4, y_fixed + 5, r_fixed,g_fixed,b_fixed);
	gfx.PutPixel(x_fixed + 5, y_fixed + 5, r_fixed,g_fixed,b_fixed);
	//上方纵向线	 	ixedf		fixed	
	gfx.PutPixel(x_fixed - 5, y_fixed + 4, r_fixed,g_fixed,b_fixed);
	gfx.PutPixel(x_fixed - 5, y_fixed + 3, r_fixed,g_fixed,b_fixed);
	gfx.PutPixel(x_fixed + 5, y_fixed + 4, r_fixed,g_fixed,b_fixed);
	gfx.PutPixel(x_fixed + 5, y_fixed + 3, r_fixed,g_fixed,b_fixed);
	//			  	ixedf		fixed
	gfx.PutPixel(x_fixed - 5, y_fixed - 5, r_fixed,g_fixed,b_fixed);
	gfx.PutPixel(x_fixed - 4, y_fixed - 5, r_fixed,g_fixed,b_fixed);
	gfx.PutPixel(x_fixed - 3, y_fixed - 5, r_fixed,g_fixed,b_fixed);
	gfx.PutPixel(x_fixed + 3, y_fixed - 5, r_fixed,g_fixed,b_fixed);
	gfx.PutPixel(x_fixed + 4, y_fixed - 5, r_fixed,g_fixed,b_fixed);
	gfx.PutPixel(x_fixed + 5, y_fixed - 5, r_fixed,g_fixed,b_fixed);
	//			  	ixedf		fixed
	gfx.PutPixel(x_fixed - 5, y_fixed - 4, r_fixed,g_fixed,b_fixed);
	gfx.PutPixel(x_fixed - 5, y_fixed - 3, r_fixed,g_fixed,b_fixed);
	gfx.PutPixel(x_fixed + 5, y_fixed - 4, r_fixed,g_fixed,b_fixed);
	gfx.PutPixel(x_fixed + 5, y_fixed - 3, r_fixed,g_fixed,b_fixed);


//然后先定义移动方框属性和逻辑判断，再绘制移动方框
	int r_mobile = 0;
	int	g_mobile = 0;
	int	b_mobile = 0;

	if (Colliding)
	{
		r_mobile = 255;
		g_mobile = 0;
		b_mobile = 0;

	}
	else//默认形状
	{
		r_mobile = 255;
		g_mobile = 255;
		b_mobile = 255;

	}
	gfx.PutPixel(x_mobile - 5, y_mobile + 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile - 4, y_mobile + 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile - 3, y_mobile + 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 3, y_mobile + 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 4, y_mobile + 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 5, y_mobile + 5, r_mobile, g_mobile, b_mobile);
	//上方纵向线	 							   mobile	 mobile	   mobile
	gfx.PutPixel(x_mobile - 5, y_mobile + 4, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile - 5, y_mobile + 3, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 5, y_mobile + 4, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 5, y_mobile + 3, r_mobile, g_mobile, b_mobile);
	//			  							   mobile	 mobile	   mobile
	gfx.PutPixel(x_mobile - 5, y_mobile - 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile - 4, y_mobile - 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile - 3, y_mobile - 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 3, y_mobile - 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 4, y_mobile - 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 5, y_mobile - 5, r_mobile, g_mobile, b_mobile);
	//			  							   mobile	 mobile	   mobile
	gfx.PutPixel(x_mobile - 5, y_mobile - 4, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile - 5, y_mobile - 3, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 5, y_mobile - 4, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 5, y_mobile - 3, r_mobile, g_mobile, b_mobile);
}