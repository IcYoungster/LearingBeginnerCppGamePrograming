#pragma once
#include"Graphics.h"
#include"Keyboard.h"
class Dude 
{
public:
	void ClampDude();
	/*�ĸ�getterΪ�˽����ײ����ﲻ�ܷ���x��y������*/
	int		   getX() const;
	int		   getY() const;
	//��̬static�����ĺô��Ǻ�ʵ���޹أ�Ҳ���ǲ�����Dudeʵ��Ҳ���Զ�ȡWidth��Height��Dude::GetWidth()
	static int getWidth();
	static int getHeight();
	/*������Dude�ƶ��Ĵ���鵽Dude���У���Ҫ�ü��̿��ƣ����Ծ�̬����(���ܶԴ��ݽ��������ݽ��иı�)��kbd*/
	/*���������const��ָ�����޸ĳ�Ա��������*/
	void Update(const Keyboard& kbd);	//ͬʱ�������Ҳ�����˲ٿط�ʽΪֻ���ü���
	void Draw(Graphics& gfx) const;
private:
	int x = 300;
	int y = 300;
	static constexpr int Height = 20;
	static constexpr int Width = 20;
};