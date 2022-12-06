#include"Snake.h"
#include<random>

class Goal
{
public:
	/*用来初始化，直接调用重生函数*/
	Goal(std::mt19937 rng, const Board& brd, const Snake& snk);
	/*被蛇吃掉后（与蛇头碰撞）随机初始化到Board上*/
	void Respawn(std::mt19937 rng, const Board& brd,const Snake& snk);
	/*在Board上绘制Goal*/
	void Draw(Board& brd)const;
	/*返回位置用来检测是否与蛇头碰撞*/
	const Location& GetLocation()const;
private:
	static constexpr Color c = Colors::Red;
	Location loc;
};