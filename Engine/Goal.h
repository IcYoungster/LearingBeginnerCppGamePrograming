#include"Snake.h"
#include<random>

class Goal
{
public:
	/*������ʼ����ֱ�ӵ�����������*/
	Goal(std::mt19937 rng, const Board& brd, const Snake& snk);
	/*���߳Ե�������ͷ��ײ�������ʼ����Board��*/
	void Respawn(std::mt19937 rng, const Board& brd,const Snake& snk);
	/*��Board�ϻ���Goal*/
	void Draw(Board& brd)const;
	/*����λ����������Ƿ�����ͷ��ײ*/
	const Location& GetLocation()const;
private:
	static constexpr Color c = Colors::Red;
	Location loc;
};