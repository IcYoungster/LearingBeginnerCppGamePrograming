//����Location����ֻϣ���򵥽���x��y�󶨵�һ��û�б�Ҫ��װ����
class Location
{
public:
	/*�趨һ����Ա����������λ�����deltaֵ*/
	void Add(const Location& delta)
	{
		x += delta.x;
		y += delta.y;
	}
	/*�Զ��������==���ж������Ƿ���ȣ���ֵ�Ǻ����������������Ƚϵģ���ֵ�Ǵ���ȥ�Ĳ���*/
	/*�Զ���֮���Ǽ򵥵����ݽṹ�ˣ��������ǽ�Location��ΪClass*/
	bool operator==(const Location& rv)const
	{
		return x == rv.x && y == rv.y;
	}
	int x;
	int y;
};