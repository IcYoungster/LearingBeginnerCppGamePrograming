#include "MainWindow.h"
#include "Game.h"
#include "SpriteCode.h"

/*��ʼ��ʵ��*/
Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	rng(std::random_device()()),
	snake({2,2}),
	goal(rng,brd,snake)
{
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

//������Ϸ����
void Game::UpdateModel()
{
	if (!GameIsOver)
	{
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			delta_loc = { 0,-1 };
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			delta_loc = { 0,1 };
		}
		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			delta_loc = { -1,0 };
		}
		if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			delta_loc = { 1,0 };
		}
		++snakeMoveCounter;
		if (snakeMoveCounter >= snakeMoveFrequecy)
		{
			snakeMoveCounter = 0;
			const Location next = snake.GetNextHeadLocation(delta_loc);
			if (!brd.IsInsideBoard(next)||snake.IsTouchedTileExceptEnd(next))
			{
				GameIsOver = true;
			}
			else
			{
				/*����Snake,������Ҫ�ڳԵ�֮�����ƶ�Snake�ٸ���Goal*/

				/*next == goal.GetLocation()��һ�����壬���ص�Ҳ��boolֵ*/
				const bool EatGoal = next == goal.GetLocation();
				//if (wnd.kbd.KeyIsPressed(VK_CONTROL))/*������������*/
				if(EatGoal)
				{
					snake.Grow();
				}
				snake.MoveBy(delta_loc);
				if (EatGoal)
				{
					goal.Respawn(rng, brd, snake);
				}
			}
		}
	}
}

void Game::ComposeFrame()
{
	snake.Draw(brd);
	goal.Draw(brd);
	if (GameIsOver)
	{
		SpriteCodex::DrawGameOver(200, 200, gfx);
	}
}