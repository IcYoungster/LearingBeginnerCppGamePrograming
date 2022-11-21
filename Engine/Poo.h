#pragma once
#include"Graphics.h"
#include"Dude.h"
class Poo {
public:
	void Init(int ini_x,int ini_y,int ini_vx, int ini_vy);/*构造函数改为自定义初始化函数*/
	void Update();
	bool IsEat() const;
	void CollidingTest(const Dude& dude);
	void Draw(Graphics& gfx) const;
private:
	int x;
	int y;
	int vx;
	int vy;
	bool IsEaten = false;
	bool PooIsInitialized = false;
	static constexpr int Width = 24;
	static constexpr int Height = 24;
};