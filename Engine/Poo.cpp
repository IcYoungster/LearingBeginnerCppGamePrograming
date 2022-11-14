#include"Poo.h"
#include"Graphics.h"
#include<random>
void Poo::Update()
{
	/*Poo�ƶ��ٶ��趨*/
	x += vx;
	y += vy;
	/*Poo�ƶ��ٶ��趨*/

	/*����Poo����Ļ��*/
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
	/*����Poo����Ļ��*/

}

void Poo::CollidingTest(int dudex, int dudey, int dwidth, int dheight)
{
	/*��ײ���*/
	const int dright = dudex + dwidth;
	const int dbottom = dudey + dheight;
	const int pright = x + Width;//��Ϊx��poo��xֵ
	const int pbottom = y + Height;
	if(	x		<= dright&&
		dudex	<= pright&&
		y		<= dbottom&&
		dudey	<= pbottom)
	{
		IsEaten = true;
	}
	/*��ײ���*/
}

void Poo::RandomNumG()
{
	std::random_device rd;//���������������Ȼ�����ó�������������������Դ������������Ҫ��mt��
	std::mt19937 rng(rd());	//��������������ÿ����������������һ��
	//which means random number generator
	//mersenne twister:ͨ��α�������������������Դ�����ڳ���Ϊ÷ɭ����
	std::uniform_int_distribution<int> xDist(0, 776);
	std::uniform_int_distribution<int> yDist(0, 576);
	x = xDist(rng);
	y = yDist(rng);
	//�����ɷ�Χ��-����~����ƽ���ֲ������ͷ�Χ0~776,�������ڱ�ʾ��������ͣ�����ΪxDist
}