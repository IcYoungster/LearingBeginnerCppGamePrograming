#include "Graphics.h"
#include "Dude.h"
#include<random>
class Rect
{
public:
	void Init(int ini_x, int ini_y);
	void Draw(Graphics& gfx) const;
	void CollidingTest(const Dude& Dude);
	bool IsEat();
	void SetEat(bool var);
private:
	static constexpr int width = 20;
	static constexpr int height = 20;
	int x;
	int y;
	bool IsEaten = false;
};
