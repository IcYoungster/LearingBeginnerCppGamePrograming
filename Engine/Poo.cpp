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

void Poo::CollidingTest(int dudex, int dudey, int dwidth, int dheight)
{
	/*碰撞检测*/
	const int dright = dudex + dwidth;
	const int dbottom = dudey + dheight;
	const int pright = x + Width;//因为x是poo的x值
	const int pbottom = y + Height;
	if(	x		<= dright&&
		dudex	<= pright&&
		y		<= dbottom&&
		dudey	<= pbottom)
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