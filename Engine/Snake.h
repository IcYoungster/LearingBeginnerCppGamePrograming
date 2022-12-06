#include"Board.h"

class Snake
{
private:
	class Segment
	{
	public:
		/*这两个函数用来初始化蛇长度增加时的Segments*/
		void InitHead(const Location& ini_loc);//创建蛇时候指定头的位置
		void InitBody();//不需要参数，已经设定为跟随头
		/*从尾到头，每个片段移动到下一个片段位置上*/
		void Follow(const Segment& next);
		/*将头移动一个delta单位*/
		void MoveHead(const Location& delta_loc);
		/*绘制片段到Board*/
		void Draw(Board& brd);
		/*为了获取特定分段的位置需要将Location解封装,可以按引用返回值*/
		const Location& GetLocation() const;
	private:
		/*Snake每个分段和Goal都包含了位置、颜色信息*/
		Location loc;
		Color c;
	};
public:
	/*构造函数，确定Snake在网格上的起始点*/
	Snake(const Location& loc);
	/*将蛇移动一个特定delta值（如1，0将蛇整体向x正向移动1点）*/
	void MoveBy(const Location& delta_loc);
	/*获取下一个头的位置，判断是否会碰到自己身体，只能按值返回，否则会在返回一个值后销毁位置*/
	Location GetNextHeadLocation(const Location& delta_loc) const;
	/*失败条件2：判断蛇头是否碰到自己的身体*/
	bool IsTouchedTileExceptEnd(const Location& tileLoc) const;
	/*用来判断要生成的Goal是否与蛇的身体重合*/
	bool IsTouchedSnake(const Location& tileLoc) const;
	/*让蛇增加长度*/
	void Grow();
	/*绘制蛇到Board*/
	void Draw(Board& brd);
	
private:
	/*定义蛇的颜色*/
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;
	/*Snake的私有变量里定义Segments最大数量*/
	static constexpr int nSegmentsMax = 100;
	/*定义Segments数组作为蛇的最大长度，随着吃掉的Goal增加，数组已使用部分增加而未使用部分减少*/
	Segment s[nSegmentsMax];
	/*已使用的Segments数量&没使用的第一个Segments索引*/
	int nSegments = 1;
};
