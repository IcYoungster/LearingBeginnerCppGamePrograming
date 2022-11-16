#pragma once
#include"Graphics.h"
#include"Dude.h"
class Poo {
public:
	int x;
	int y;
	int vx;
	int vy;
	bool IsEaten = false;
	static constexpr int Width = 24;
	static constexpr int Height = 24;
	void Update();
	void CollidingTest(const Dude& dude);
	void RandomNumG();
	void Draw(Graphics& gfx) const;
};