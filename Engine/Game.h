/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	
	//储存初始颜色的变量
	int R = 255;
	
	//任务2：将变更方向改为变更速度
	int x = 400;
	int y = 300;
	
	//限定每帧移动的像素数量
	const int pmove = 3;
	
	//给像素移动添加加速度，位置改变->速度改变。
	//加速度值设为1，目前没有特殊处理，按下按键其速度每帧增加1
	const int a = 1;
	int vx = 0;
	int vy = 0;
	
	//任务1的部分：实现形状变化逻辑和绘图分离，需要一个变量储存绘制图形的状态，默认为未改变，
	//当按下对应的键位，改变其值为true
	bool ShapeIsChanged = false;

	//任务3：抑制后59帧的渲染，存放在变量里
	bool inhibitUp = false;
	bool inhibitDown = false;
	bool inhibitLeft = false;
	bool inhibitRight = false;
	/********************************/
	/*  User Variables              */
	/********************************/
};