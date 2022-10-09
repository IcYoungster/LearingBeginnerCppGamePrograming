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

void Game::UpdateModel()//����1�����߼����ֺͻ�ͼ���ַ���
{
	//�������׼�ĵĻ���λ��,Ϊ�˷�ֹ�仭����ǰ��Ļ�⣬��СֵӦΪ5

	//����3����ÿ֡���ӵ��ٶȸ�Ϊÿ�����ӵ��ٶȣ���Ҫ�����ٶ�����ֻ�ڵ�һ֡��֮��59֡����ˢ����60Ϊ�������ı����ֵ

	//����ԭ�����ж��Ƿ��°����������£����ж��Ƿ񱻿��ƣ�������������Ǿ�ʲô��������ֱ���ɿ�����������inhibitUp��ֵΪfalse
	//��һ�ν���������ִ��inhibitUp��elseģ�飬֮��inhibitUp��Ϊtrue����ôֱ���ɿ�����֮ǰ�Ͷ������κβ���
	//����ʵ���˰�һ�μ���һ���ٶ�
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
	//��x���ϼ��ٶȣ���СΪ�������õ�ֵ��
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
	if (ShapeIsChanged)//������״
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
	else//Ĭ����״
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