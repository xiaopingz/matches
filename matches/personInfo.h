#pragma once
class PersonInfo
{
public:
	PersonInfo(void);
	PersonInfo(int id,int wealth,int look,int charactor,int rw,int rl, int rc);
	~PersonInfo(void);

public:
	void	showInfo();
	void	assign(int id, int wealth, int look, int charactor, int rw, int rl, int rc);
	int		calculateDegree(PersonInfo target);	//���㵥������ȣ�����Ϊ������Ķ���
	int		sumOfInfo();
	int		getUsrID();
	int		getRW();	//��ȡ��������Ķ�Ӧ�����ı���
	int		getRL();
	int		getRC();

protected:
	int m_userID;
	int m_info_wealth;		//���˲Ƹ�: ȡֵ1~100
	int m_info_look;		//������ò��ȡֵ1~100
	int m_info_charactor;	//����Ʒ��ȡֵ1~100
	int m_ratio_wealth;
	int m_ratio_look;
	int m_ratio_charactor;	//����ż����ָ��������ٷֱȣ����ߺ�Ϊ100������ȡֵ1~98
};

