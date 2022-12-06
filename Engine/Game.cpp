#include "MainWindow.h"
#include "Game.h"
#include "SpriteCode.h"

/*初始化实例*/
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

//更新游戏画面
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
				/*更新Snake,这里需要在吃掉之后先移动Snake再更新Goal*/

				/*next == goal.GetLocation()是一个整体，返回的也是bool值*/
				const bool EatGoal = next == goal.GetLocation();
				//if (wnd.kbd.KeyIsPressed(VK_CONTROL))/*测试生长代码*/
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