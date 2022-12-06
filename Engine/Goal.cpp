#include "Goal.h"

Goal::Goal(std::mt19937 rng, const Board& brd, const Snake& snk)
{
	Respawn(rng, brd, snk);
}

void Goal::Respawn(std::mt19937 rng, const Board& brd, const Snake& snk)
{
	/*分布到0~网格最边缘*/
	std::uniform_int_distribution<int> xDist(0, brd.GetGridWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, brd.GetGridHeight() - 1);
	/*将Goal分布到Snake以外的空处*/
	Location newLoc;
	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while (snk.IsTouchedSnake(newLoc));

	loc = newLoc;
}

void Goal::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

const Location& Goal::GetLocation() const
{
	return loc;
	// TODO: 在此处插入 return 语句
}
