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
	/*����Ķ���Ƕ�����*/
	
	MainWindow& wnd;
	Graphics gfx;
	Board brd;
	Snake snake;
	Location delta_loc = { 1,0 };//����delta��Ϊx����1��
	std::mt19937 rng;
	Goal goal;
	//������ÿ֡+1����20��frequency�����������㣬��ˢ����Ϊ60��һ���ƶ�������λ
	static constexpr int snakeMoveFrequecy = 20;
	int snakeMoveCounter = 0;
	bool GameIsOver = false;
};