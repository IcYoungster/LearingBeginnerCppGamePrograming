#include"Poo.h"
#include"Graphics.h"
#include<random>
void Poo::Update()
{
	/*Poo移动速度设定*/
	x += vx;
	y += vy;
	/*Poo移动速度设定*/

	/*限制Poo在屏幕内*/
	const int bottom = y + Height;
	if (y < 0)
	{
		y = 0;
		vy = -vy;
	}
	else if (bottom >= Graphics::ScreenHeight)
	{
		y = Graphics::ScreenHeight - 1 - Height;
		vy = -vy;
	}
	const int right = x + Width;
	if (x < 0)
	{
		x = 0;
		vx = -vx;
	}
	else if (right >= Graphics::ScreenWidth)
	{
		x = Graphics::ScreenWidth - 1 - Width;
		vx = -vx;
	}
	/*限制Poo在屏幕内*/

}

void Poo::CollidingTest(const Dude& dude)
{
	/*碰撞检测*/
	const int dright = dude.x + dude.Width;
	const int dbottom = dude.y + dude.Height;
	const int pright = x + Width;//因为x是poo的x值
	const int pbottom = y + Height;
	if(	x		<= dright&&
		dude.x	<= pright&&
		y		<= dbottom&&
		dude.y	<= pbottom)
	{
		IsEaten = true;
	}
	/*碰撞检测*/
}

void Poo::RandomNumG()
{
	std::random_device rd;//随机种子生成器，然而不擅长创建大量随机数，所以创建随机数还是要让mt来
	std::mt19937 rng(rd());	//这个随机数生成器每次重启的种子数都一样
	//which means random number generator
	//mersenne twister:通用伪随机数生成器，名字来源于周期长度为梅森素数
	std::uniform_int_distribution<int> xDist(0, 776);
	std::uniform_int_distribution<int> yDist(0, 576);
	x = xDist(rng);
	y = yDist(rng);
	//将生成范围的-两亿~两亿平均分布到整型范围0~776,尖括号内表示输出的类型，命名为xDist
}

void Poo::Draw(Graphics &gfx) const
{
	gfx.PutPixel(14 + x, 0 + y, 138, 77, 0);
	gfx.PutPixel(7 + x, 1 + y, 138, 77, 0);
	gfx.PutPixel(13 + x, 1 + y, 138, 77, 0);
	gfx.PutPixel(20 + x, 1 + y, 138, 77, 0);
	gfx.PutPixel(6 + x, 2 + y, 138, 77, 0);
	gfx.PutPixel(13 + x, 2 + y, 138, 77, 0);
	gfx.PutPixel(20 + x, 2 + y, 138, 77, 0);
	gfx.PutPixel(6 + x, 3 + y, 138, 77, 0);
	gfx.PutPixel(6 + x, 4 + y, 138, 77, 0);
	gfx.PutPixel(14 + x, 4 + y, 138, 77, 0);
	gfx.PutPixel(21 + x, 4 + y, 138, 77, 0);
	gfx.PutPixel(7 + x, 5 + y, 138, 77, 0);
	gfx.PutPixel(13 + x, 5 + y, 138, 77, 0);
	gfx.PutPixel(21 + x, 5 + y, 138, 77, 0);
	gfx.PutPixel(7 + x, 6 + y, 138, 77, 0);
	gfx.PutPixel(20 + x, 6 + y, 138, 77, 0);
	gfx.PutPixel(6 + x, 7 + y, 138, 77, 0);
	gfx.PutPixel(14 + x, 7 + y, 51, 28, 0);
	gfx.PutPixel(15 + x, 7 + y, 51, 28, 0);
	gfx.PutPixel(20 + x, 7 + y, 138, 77, 0);
	gfx.PutPixel(12 + x, 8 + y, 51, 28, 0);
	gfx.PutPixel(13 + x, 8 + y, 51, 28, 0);
	gfx.PutPixel(14 + x, 8 + y, 51, 28, 0);
	gfx.PutPixel(7 + x, 9 + y, 138, 77, 0);
	gfx.PutPixel(11 + x, 9 + y, 51, 28, 0);
	gfx.PutPixel(12 + x, 9 + y, 102, 57, 0);
	gfx.PutPixel(13 + x, 9 + y, 138, 77, 0);
	gfx.PutPixel(14 + x, 9 + y, 138, 77, 0);
	gfx.PutPixel(15 + x, 9 + y, 51, 28, 0);
	gfx.PutPixel(21 + x, 9 + y, 138, 77, 0);
	gfx.PutPixel(10 + x, 10 + y, 51, 28, 0);
	gfx.PutPixel(11 + x, 10 + y, 51, 28, 0);
	gfx.PutPixel(12 + x, 10 + y, 102, 57, 0);
	gfx.PutPixel(13 + x, 10 + y, 138, 77, 0);
	gfx.PutPixel(14 + x, 10 + y, 138, 77, 0);
	gfx.PutPixel(15 + x, 10 + y, 51, 28, 0);
	gfx.PutPixel(20 + x, 10 + y, 138, 77, 0);
	gfx.PutPixel(9 + x, 11 + y, 51, 28, 0);
	gfx.PutPixel(10 + x, 11 + y, 138, 77, 0);
	gfx.PutPixel(11 + x, 11 + y, 138, 77, 0);
	gfx.PutPixel(12 + x, 11 + y, 51, 28, 0);
	gfx.PutPixel(13 + x, 11 + y, 51, 28, 0);
	gfx.PutPixel(14 + x, 11 + y, 51, 28, 0);
	gfx.PutPixel(15 + x, 11 + y, 51, 28, 0);
	gfx.PutPixel(16 + x, 11 + y, 51, 28, 0);
	gfx.PutPixel(9 + x, 12 + y, 51, 28, 0);
	gfx.PutPixel(10 + x, 12 + y, 138, 77, 0);
	gfx.PutPixel(11 + x, 12 + y, 138, 77, 0);
	gfx.PutPixel(12 + x, 12 + y, 111, 62, 0);
	gfx.PutPixel(13 + x, 12 + y, 102, 57, 0);
	gfx.PutPixel(14 + x, 12 + y, 102, 57, 0);
	gfx.PutPixel(15 + x, 12 + y, 102, 57, 0);
	gfx.PutPixel(16 + x, 12 + y, 51, 28, 0);
	gfx.PutPixel(9 + x, 13 + y, 51, 28, 0);
	gfx.PutPixel(10 + x, 13 + y, 109, 61, 0);
	gfx.PutPixel(11 + x, 13 + y, 138, 77, 0);
	gfx.PutPixel(12 + x, 13 + y, 138, 77, 0);
	gfx.PutPixel(13 + x, 13 + y, 138, 77, 0);
	gfx.PutPixel(14 + x, 13 + y, 138, 77, 0);
	gfx.PutPixel(15 + x, 13 + y, 138, 77, 0);
	gfx.PutPixel(16 + x, 13 + y, 51, 28, 0);
	gfx.PutPixel(5 + x, 14 + y, 51, 28, 0);
	gfx.PutPixel(7 + x, 14 + y, 51, 28, 0);
	gfx.PutPixel(8 + x, 14 + y, 51, 28, 0);
	gfx.PutPixel(9 + x, 14 + y, 51, 28, 0);
	gfx.PutPixel(10 + x, 14 + y, 51, 28, 0);
	gfx.PutPixel(11 + x, 14 + y, 138, 77, 0);
	gfx.PutPixel(12 + x, 14 + y, 138, 77, 0);
	gfx.PutPixel(13 + x, 14 + y, 138, 77, 0);
	gfx.PutPixel(14 + x, 14 + y, 138, 77, 0);
	gfx.PutPixel(15 + x, 14 + y, 138, 77, 0);
	gfx.PutPixel(16 + x, 14 + y, 51, 28, 0);
	gfx.PutPixel(4 + x, 15 + y, 51, 28, 0);
	gfx.PutPixel(5 + x, 15 + y, 138, 77, 0);
	gfx.PutPixel(6 + x, 15 + y, 51, 28, 0);
	gfx.PutPixel(7 + x, 15 + y, 116, 65, 0);
	gfx.PutPixel(8 + x, 15 + y, 138, 77, 0);
	gfx.PutPixel(9 + x, 15 + y, 138, 77, 0);
	gfx.PutPixel(10 + x, 15 + y, 138, 77, 0);
	gfx.PutPixel(11 + x, 15 + y, 51, 28, 0);
	gfx.PutPixel(12 + x, 15 + y, 51, 28, 0);
	gfx.PutPixel(13 + x, 15 + y, 51, 28, 0);
	gfx.PutPixel(14 + x, 15 + y, 51, 28, 0);
	gfx.PutPixel(15 + x, 15 + y, 51, 28, 0);
	gfx.PutPixel(16 + x, 15 + y, 51, 28, 0);
	gfx.PutPixel(17 + x, 15 + y, 51, 28, 0);
	gfx.PutPixel(18 + x, 15 + y, 51, 28, 0);
	gfx.PutPixel(1 + x, 16 + y, 51, 28, 0);
	gfx.PutPixel(2 + x, 16 + y, 51, 28, 0);
	gfx.PutPixel(3 + x, 16 + y, 51, 28, 0);
	gfx.PutPixel(4 + x, 16 + y, 51, 28, 0);
	gfx.PutPixel(5 + x, 16 + y, 138, 77, 0);
	gfx.PutPixel(6 + x, 16 + y, 51, 28, 0);
	gfx.PutPixel(7 + x, 16 + y, 116, 65, 0);
	gfx.PutPixel(8 + x, 16 + y, 138, 77, 0);
	gfx.PutPixel(9 + x, 16 + y, 138, 77, 0);
	gfx.PutPixel(10 + x, 16 + y, 138, 77, 0);
	gfx.PutPixel(11 + x, 16 + y, 138, 77, 0);
	gfx.PutPixel(12 + x, 16 + y, 138, 77, 0);
	gfx.PutPixel(13 + x, 16 + y, 109, 61, 0);
	gfx.PutPixel(14 + x, 16 + y, 51, 28, 0);
	gfx.PutPixel(15 + x, 16 + y, 138, 77, 0);
	gfx.PutPixel(16 + x, 16 + y, 138, 77, 0);
	gfx.PutPixel(17 + x, 16 + y, 138, 77, 0);
	gfx.PutPixel(18 + x, 16 + y, 123, 69, 0);
	gfx.PutPixel(19 + x, 16 + y, 51, 28, 0);
	gfx.PutPixel(0 + x, 17 + y, 51, 28, 0);
	gfx.PutPixel(1 + x, 17 + y, 87, 49, 0);
	gfx.PutPixel(2 + x, 17 + y, 87, 49, 0);
	gfx.PutPixel(3 + x, 17 + y, 87, 49, 0);
	gfx.PutPixel(4 + x, 17 + y, 87, 49, 0);
	gfx.PutPixel(5 + x, 17 + y, 51, 28, 0);
	gfx.PutPixel(6 + x, 17 + y, 51, 28, 0);
	gfx.PutPixel(7 + x, 17 + y, 43, 24, 0);
	gfx.PutPixel(8 + x, 17 + y, 51, 28, 0);
	gfx.PutPixel(9 + x, 17 + y, 51, 28, 0);
	gfx.PutPixel(10 + x, 17 + y, 51, 28, 0);
	gfx.PutPixel(11 + x, 17 + y, 51, 28, 0);
	gfx.PutPixel(12 + x, 17 + y, 51, 28, 0);
	gfx.PutPixel(13 + x, 17 + y, 40, 22, 0);
	gfx.PutPixel(14 + x, 17 + y, 51, 28, 0);
	gfx.PutPixel(15 + x, 17 + y, 138, 77, 0);
	gfx.PutPixel(16 + x, 17 + y, 138, 77, 0);
	gfx.PutPixel(17 + x, 17 + y, 138, 77, 0);
	gfx.PutPixel(18 + x, 17 + y, 123, 69, 0);
	gfx.PutPixel(19 + x, 17 + y, 51, 28, 0);
	gfx.PutPixel(0 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(1 + x, 18 + y, 138, 77, 0);
	gfx.PutPixel(2 + x, 18 + y, 138, 77, 0);
	gfx.PutPixel(3 + x, 18 + y, 138, 77, 0);
	gfx.PutPixel(4 + x, 18 + y, 138, 77, 0);
	gfx.PutPixel(5 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(6 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(7 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(8 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(9 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(10 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(11 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(12 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(13 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(14 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(15 + x, 18 + y, 138, 77, 0);
	gfx.PutPixel(16 + x, 18 + y, 138, 77, 0);
	gfx.PutPixel(17 + x, 18 + y, 138, 77, 0);
	gfx.PutPixel(18 + x, 18 + y, 123, 69, 0);
	gfx.PutPixel(19 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(20 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(21 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(22 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(0 + x, 19 + y, 51, 28, 0);
	gfx.PutPixel(1 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(2 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(3 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(4 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(5 + x, 19 + y, 51, 28, 0);
	gfx.PutPixel(6 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(7 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(8 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(9 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(10 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(11 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(12 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(13 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(14 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(15 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(16 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(17 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(18 + x, 19 + y, 123, 69, 0);
	gfx.PutPixel(19 + x, 19 + y, 51, 28, 0);
	gfx.PutPixel(20 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(21 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(22 + x, 19 + y, 65, 36, 0);
	gfx.PutPixel(23 + x, 19 + y, 51, 28, 0);
	gfx.PutPixel(1 + x, 20 + y, 51, 28, 0);
	gfx.PutPixel(2 + x, 20 + y, 51, 28, 0);
	gfx.PutPixel(3 + x, 20 + y, 51, 28, 0);
	gfx.PutPixel(4 + x, 20 + y, 51, 28, 0);
	gfx.PutPixel(5 + x, 20 + y, 51, 28, 0);
	gfx.PutPixel(6 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(7 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(8 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(9 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(10 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(11 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(12 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(13 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(14 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(15 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(16 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(17 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(18 + x, 20 + y, 123, 69, 0);
	gfx.PutPixel(19 + x, 20 + y, 51, 28, 0);
	gfx.PutPixel(20 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(21 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(22 + x, 20 + y, 65, 36, 0);
	gfx.PutPixel(23 + x, 20 + y, 51, 28, 0);
	gfx.PutPixel(0 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(1 + x, 21 + y, 138, 77, 0);
	gfx.PutPixel(2 + x, 21 + y, 138, 77, 0);
	gfx.PutPixel(3 + x, 21 + y, 138, 77, 0);
	gfx.PutPixel(4 + x, 21 + y, 138, 77, 0);
	gfx.PutPixel(5 + x, 21 + y, 138, 77, 0);
	gfx.PutPixel(6 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(7 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(8 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(9 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(10 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(11 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(12 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(13 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(14 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(15 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(16 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(17 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(18 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(20 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(21 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(22 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(0 + x, 22 + y, 51, 28, 0);
	gfx.PutPixel(1 + x, 22 + y, 65, 36, 0);
	gfx.PutPixel(2 + x, 22 + y, 65, 36, 0);
	gfx.PutPixel(3 + x, 22 + y, 65, 36, 0);
	gfx.PutPixel(4 + x, 22 + y, 65, 36, 0);
	gfx.PutPixel(5 + x, 22 + y, 65, 36, 0);
	gfx.PutPixel(6 + x, 22 + y, 51, 28, 0);
	gfx.PutPixel(1 + x, 23 + y, 51, 28, 0);
	gfx.PutPixel(2 + x, 23 + y, 51, 28, 0);
	gfx.PutPixel(3 + x, 23 + y, 51, 28, 0);
	gfx.PutPixel(4 + x, 23 + y, 51, 28, 0);
	gfx.PutPixel(5 + x, 23 + y, 51, 28, 0);
	gfx.PutPixel(6 + x, 23 + y, 51, 28, 0);
}