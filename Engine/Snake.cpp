#include "Snake.h"
#include <assert.h>
Snake::Snake(const Location& loc)
{
	/*��ʼ��ͷ��λ��*/
	s[0].InitHead(loc);
}

void Snake::MoveBy(const Location& delta_loc)
{
	for (int i = nSegments - 1; i > 0; i--)
	{
		/*�����һ�ʼ����ǰһ���ƶ�*/
		s[i].Follow(s[i - 1]);
	}
	/*��ͷ�ƶ�һ��delta��λ*/
	s[0].MoveHead(delta_loc);
}

Location Snake::GetNextHeadLocation(const Location& delta_loc) const
{
	/*Ϊ�˻�ȡ�ض��ֶε�λ����Ҫ�Ƚ�Location���װ*/
	Location l(s[0].GetLocation());//��ʼ��Ϊͷ��λ�õĸ���
	l.Add(delta_loc);//����deltaֵ���λ�ã�����һ��ͷ����λ��
	return l;
}

bool Snake::IsTouchedTileExceptEnd(const Location& tileLoc) const
{
	/*������ʹ��segments�������һ�Σ�����β���ƶ�����һ֡������������ǰ������Ϸ��
	������TileLoc���˵�����������壬����true*/
	for (int i = 0; i < nSegments-1; i++)
	{
		/*�����location�����κ���֪���ͣ�����Ҫ����һ�������*/
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
	/*�ж�segment�Ƿ������꣬���¸�δʹ��segment��ʼ��ΪBody��������ʹ��segment����*/
	if (nSegments < nSegmentsMax)
	{
		s[nSegments].InitBody();
		nSegments++;
	}
}

void Snake::Draw(Board& brd)
{
	/*����ÿ��Segments������Segment��Draw����*/
	for (int i = 0; i < nSegments; i++)
	{
		s[i].Draw(brd);
	}
}

void Snake::Segment::InitHead(const Location& ini_loc)
{
	/*��ʼ��Segment��һ��趨λ�ú���ɫ*/
	loc = ini_loc;
	c = Snake::headColor;
}

void Snake::Segment::InitBody()
{
	/*�趨��ɫ����*/
	c = Snake::bodyColor;
}

void Snake::Segment::Follow(const Segment& next)
{
	/*����ǰsegmentλ�ø�Ϊ��һ��segmentλ��*/
	loc = next.loc;
}

void Snake::Segment::MoveHead(const Location& delta_loc)
{
	/*ȷ��deltaֵ��Ч,ͬʱֻ����x��y�е�һ�������ƶ�*/
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	/*segmentλ��ֵ����һ��deltaֵ*/
	loc.Add(delta_loc);
}

void Snake::Segment::Draw(Board& brd)
{
	/*��Board���������ͨ�ú���*/
	brd.DrawCell(loc, c);
}

const Location& Snake::Segment::GetLocation() const
{
	return loc;
}
