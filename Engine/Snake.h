#include"Board.h"

class Snake
{
private:
	class Segment
	{
	public:
		/*����������������ʼ���߳�������ʱ��Segments*/
		void InitHead(const Location& ini_loc);//������ʱ��ָ��ͷ��λ��
		void InitBody();//����Ҫ�������Ѿ��趨Ϊ����ͷ
		/*��β��ͷ��ÿ��Ƭ���ƶ�����һ��Ƭ��λ����*/
		void Follow(const Segment& next);
		/*��ͷ�ƶ�һ��delta��λ*/
		void MoveHead(const Location& delta_loc);
		/*����Ƭ�ε�Board*/
		void Draw(Board& brd);
		/*Ϊ�˻�ȡ�ض��ֶε�λ����Ҫ��Location���װ,���԰����÷���ֵ*/
		const Location& GetLocation() const;
	private:
		/*Snakeÿ���ֶκ�Goal��������λ�á���ɫ��Ϣ*/
		Location loc;
		Color c;
	};
public:
	/*���캯����ȷ��Snake�������ϵ���ʼ��*/
	Snake(const Location& loc);
	/*�����ƶ�һ���ض�deltaֵ����1��0����������x�����ƶ�1�㣩*/
	void MoveBy(const Location& delta_loc);
	/*��ȡ��һ��ͷ��λ�ã��ж��Ƿ�������Լ����壬ֻ�ܰ�ֵ���أ�������ڷ���һ��ֵ������λ��*/
	Location GetNextHeadLocation(const Location& delta_loc) const;
	/*ʧ������2���ж���ͷ�Ƿ������Լ�������*/
	bool IsTouchedTileExceptEnd(const Location& tileLoc) const;
	/*�����ж�Ҫ���ɵ�Goal�Ƿ����ߵ������غ�*/
	bool IsTouchedSnake(const Location& tileLoc) const;
	/*�������ӳ���*/
	void Grow();
	/*�����ߵ�Board*/
	void Draw(Board& brd);
	
private:
	/*�����ߵ���ɫ*/
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;
	/*Snake��˽�б����ﶨ��Segments�������*/
	static constexpr int nSegmentsMax = 100;
	/*����Segments������Ϊ�ߵ���󳤶ȣ����ųԵ���Goal���ӣ�������ʹ�ò������Ӷ�δʹ�ò��ּ���*/
	Segment s[nSegmentsMax];
	/*��ʹ�õ�Segments����&ûʹ�õĵ�һ��Segments����*/
	int nSegments = 1;
};
