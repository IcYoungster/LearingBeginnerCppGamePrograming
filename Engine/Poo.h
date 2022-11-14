#pragma once
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
	void CollidingTest(int dudex, int dudey, int dwidth, int dheight);
	void RandomNumG();
};