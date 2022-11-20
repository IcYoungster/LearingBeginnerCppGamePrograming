#pragma once
#include"Graphics.h"
#include"Keyboard.h"
class Dude 
{
public:
	void ClampDude();
	/*四个getter为了解决碰撞检测里不能访问x和y的问题*/
	int		   getX() const;
	int		   getY() const;
	//静态static函数的好处是和实例无关，也就是不创建Dude实例也可以读取Width和Height，Dude::GetWidth()
	static int getWidth();
	static int getHeight();
	/*将控制Dude移动的代码归到Dude类中，需要用键盘控制，所以静态引用(不能对传递进来的内容进行改变)了kbd*/
	/*函数后面加const是指不能修改成员变量数据*/
	void Update(const Keyboard& kbd);	//同时这个函数也限制了操控方式为只能用键盘
	void Draw(Graphics& gfx) const;
private:
	int x = 300;
	int y = 300;
	static constexpr int Height = 20;
	static constexpr int Width = 20;
};