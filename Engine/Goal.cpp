#include "Goal.h"

Goal::Goal(std::mt19937 rng, const Board& brd, const Snake& snk)
{
	Respawn(rng, brd, snk);
}

void Goal::Respawn(std::mt19937 rng, const Board& brd, const Snake& snk)
{
	/*�ֲ���0~�������Ե*/
	std::uniform_int_distribution<int> xDist(0, brd.GetGridWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, brd.GetGridHeight() - 1);
	/*��Goal�ֲ���Snake����Ŀմ�*/
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
	// TODO: �ڴ˴����� return ���
}
