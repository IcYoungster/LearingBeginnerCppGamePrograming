#include"Graphics.h"
class Meter
{
public:
	Meter(int x, int y):
		x(x),
		y(y)
	{}
	void IncreaseLevel()
	{
		++level;
	}
	int GetLevel() const
	{
		return level;
	}
	void Draw(Graphics& gfx) const
	{
		for (int i = x; i < x + level * scale; i++)
		{
			for (int j = y; j < y + width; j++)
			{
				gfx.PutPixel(i, j, Colors::Green);
			}
		}
	}
private:
	int x;
	int y;
	static constexpr int scale = 4;//ÿ��������������
	static constexpr int width = 12;//���
	int level = 0;//�Ǳ���
};
