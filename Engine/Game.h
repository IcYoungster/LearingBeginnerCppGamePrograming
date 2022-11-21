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
	/*����Ķ���Ƕ�����*/

	MainWindow& wnd;
	Graphics gfx;

	/*����RNGʵ���������Game���캯�����ʼ��*/
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xDist;
	std::uniform_int_distribution<int> yDist;
	std::uniform_int_distribution<int> vDist;
	/*����Pooʵ��*/
	static constexpr int nPoo = 100;
	Poo Poos[nPoo];
	/*����Dudeʵ��*/
	Dude Dude;
	/*������ɫ����ʵ��*/
	static constexpr int nRect = 10;
	Rect rects[nRect];
	//Rect rect;
	
	bool IsStarted = false;
};