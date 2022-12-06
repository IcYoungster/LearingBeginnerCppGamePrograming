//对于Location我们只希望简单将其x，y绑定到一起，没有必要封装起来
class Location
{
public:
	/*设定一个成员函数帮助向位置添加delta值*/
	void Add(const Location& delta)
	{
		x += delta.x;
		y += delta.y;
	}
	/*自定义操作符==，判断左右是否相等，左值是函数调用数据用来比较的，右值是传进去的参数*/
	/*自定义之后不是简单的数据结构了，所以我们将Location改为Class*/
	bool operator==(const Location& rv)const
	{
		return x == rv.x && y == rv.y;
	}
	int x;
	int y;
};