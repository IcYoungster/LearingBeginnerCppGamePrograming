#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Goal.h"
#include <random>

class Game
{
public:
	Game(class MainWindow& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	/*下面的都是嵌入对象*/
	
	MainWindow& wnd;
	Graphics gfx;
	Board brd;
	Snake snake;
	Location delta_loc = { 1,0 };//设置delta量为x正向1格
	std::mt19937 rng;
	Goal goal;
	//计数器每帧+1，到20（frequency）计数器归零，若刷新率为60则一秒移动三个单位
	static constexpr int snakeMoveFrequecy = 20;
	int snakeMoveCounter = 0;
	bool GameIsOver = false;
};