#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Poo.h"
#include "Dude.h"
#include "Rect.h"
#include<random>

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
	void DrawGameOver(int x, int y);
	void DrawTitleScreen(int x, int y);
private:
	/*下面的都是嵌入对象*/

	MainWindow& wnd;
	Graphics gfx;

	/*创建RNG实例，随后在Game构造函数里初始化*/
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xDist;
	std::uniform_int_distribution<int> yDist;
	std::uniform_int_distribution<int> vDist;
	/*创建Poo实例*/
	static constexpr int nPoo = 100;
	Poo Poos[nPoo];
	/*创建Dude实例*/
	Dude Dude;
	/*创建红色方块实例*/
	static constexpr int nRect = 10;
	Rect rects[nRect];
	//Rect rect;
	
	bool IsStarted = false;
};