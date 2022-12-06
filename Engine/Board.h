/*Board����pixel��location����board*/
#include"Graphics.h"
#include"Location.h"
class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);/*��̬����loc��ֻ�Ƕ�ȡλ�ò����ڲ�������*/
	/*ʧ������1������ǽ��*/
	bool IsInsideBoard(const Location& loc) const;
	int GetGridWidth() const;
	int GetGridHeight() const;
private:
	/*dimention������ӵĿ��*/
	static constexpr int dimention = 20;
	/*��������������ʾBoard�ĺ����������*/
	static constexpr int width = 25;
	static constexpr int height = 25;
	Graphics& gfx;
	//�����gfx�����ã������Ͳ���ÿ�ζ����������������ڿ��Ƿ����ǰ���´洢һ�������ı��ر���
};