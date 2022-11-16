#pragma once
#include"Graphics.h"
class Dude 
{
public:
	void ClampDude();
	void Draw(Graphics& gfx) const;
	int x = 300;
	int y = 300;
	static constexpr int Height = 20;
	static constexpr int Width = 20;
};