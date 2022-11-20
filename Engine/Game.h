#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Poo.h"
#include "Dude.h"

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

	/*创建Poo实例*/
	Poo Poo0;
	Poo Poo1;
	Poo Poo2;
	/*创建Poo实例*/
	Dude Dude;
	
	bool IsStarted = false;
};