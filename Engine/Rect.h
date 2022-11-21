#include "Graphics.h"
#include "Dude.h"
#include<random>
class Rect
{
public:
	Rect(int ini_x, int ini_y);
	void Draw(Graphics& gfx) const;
	bool CollidingTest(const Dude& Dude);
	void Respawn(int ini_x,int ini_y);
	void UpdateColor();
private:
	static constexpr int side = 20;
	Color c = { 127,0,0 };
	bool colorIncreseing = true;
	int x;
	int y;
};
