#pragma once
#include"Graphics.h"
#include"Dude.h"
class Poo {
public:
	Poo(int ini_x,int ini_y,int ini_vx, int ini_vy);/*Poo的构造函数*/
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
	static constexpr int Width = 24;
	static constexpr int Height = 24;
};