/*Board控制pixel，location控制board*/
#include"Graphics.h"
#include"Location.h"
class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);/*静态引用loc，只是读取位置并基于参数绘制*/
	/*失败条件1：碰到墙壁*/
	bool IsInsideBoard(const Location& loc) const;
	int GetGridWidth() const;
	int GetGridHeight() const;
private:
	/*dimention代表格子的宽高*/
	static constexpr int dimention = 20;
	/*下面两个参数表示Board的横纵向格子数*/
	static constexpr int width = 25;
	static constexpr int height = 25;
	Graphics& gfx;
	//缓存对gfx的引用，这样就不必每次都传递它。缓存是在考虑方便的前提下存储一个拷贝的本地变量
};