#include "Snake.h"
#include <assert.h>
Snake::Snake(const Location& loc)
{
	/*初始化头的位置*/
	s[0].InitHead(loc);
}

void Snake::MoveBy(const Location& delta_loc)
{
	for (int i = nSegments - 1; i > 0; i--)
	{
		/*从最后一项开始，向前一项移动*/
		s[i].Follow(s[i - 1]);
	}
	/*将头移动一个delta单位*/
	s[0].MoveHead(delta_loc);
}

Location Snake::GetNextHeadLocation(const Location& delta_loc) const
{
	/*为了获取特定分段的位置需要先将Location解封装*/
	Location l(s[0].GetLocation());//初始化为头部位置的副本
	l.Add(delta_loc);//加上delta值后的位置，即下一个头部的位置
	return l;
}

bool Snake::IsTouchedTileExceptEnd(const Location& tileLoc) const
{
	/*遍历已使用segments除了最后一段（若在尾巴移动的上一帧检测则会错误地提前结束游戏）
	，若和TileLoc相等说明碰到了身体，返回true*/
	for (int i = 0; i < nSegments-1; i++)
	{
		/*定义的location不是任何已知类型，所以要创建一个运算符*/
		if (s[i].GetLocation() == tileLoc)
		{
			return true;
		}
	}
	return false;
}

bool Snake::IsTouchedSnake(const Location& tileLoc) const
{
	for (int i = 0; i < nSegments; i++)
	{
		if (s[i].GetLocation() == tileLoc)
		{
			return true;
		}
	}
	return false;
}

void Snake::Grow()
{
	/*判断segment是否已用完，将下个未使用segment初始化为Body，增加已使用segment数量*/
	if (nSegments < nSegmentsMax)
	{
		s[nSegments].InitBody();
		nSegments++;
	}
}

void Snake::Draw(Board& brd)
{
	/*遍历每个Segments，调用Segment的Draw函数*/
	for (int i = 0; i < nSegments; i++)
	{
		s[i].Draw(brd);
	}
}

void Snake::Segment::InitHead(const Location& ini_loc)
{
	/*初始化Segment第一项，设定位置和颜色*/
	loc = ini_loc;
	c = Snake::headColor;
}

void Snake::Segment::InitBody()
{
	/*设定颜色即可*/
	c = Snake::bodyColor;
}

void Snake::Segment::Follow(const Segment& next)
{
	/*将当前segment位置改为下一个segment位置*/
	loc = next.loc;
}

void Snake::Segment::MoveHead(const Location& delta_loc)
{
	/*确认delta值有效,同时只能向x或y中的一个方向移动*/
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	/*segment位置值加上一个delta值*/
	loc.Add(delta_loc);
}

void Snake::Segment::Draw(Board& brd)
{
	/*向Board绘制网格的通用函数*/
	brd.DrawCell(loc, c);
}

const Location& Snake::Segment::GetLocation() const
{
	return loc;
}
