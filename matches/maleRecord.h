#pragma once
#include"head_info.h"
#include"femaleRecord.h"

class maleRecord
{
public:
	maleRecord(void);
	~maleRecord(void);

public:
	//functions
	void	addMaleRecord(int id, int wealth, int look, int charactor, int rw, int rl, int rc);
	void	addDegree(femaleRecord fr);	//���ÿһ�����û�������Ů�û�����������ȡ��������Լ�¼�ܱ�δ����
	//void	sortByDegree();				//���ÿһ�����û�������ÿ��Ů���û�������Ƚ������򣬷�������ͶƱ������
	void	vote(femaleRecord fr);						//�������û�����Ů���û�����һ��ͶƱ           
	

protected:
	vector<male_data>	m_maleRecord;
};

