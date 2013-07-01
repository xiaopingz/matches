#pragma once
#include"head_info.h"
#include"FemaleRecord.h"

class MaleRecord
{
public:
	MaleRecord(void);
	~MaleRecord(void);

public:
	//functions
	male_data	getElementById(int id);
	void	addMaleRecord(int id, int wealth, int look, int charactor, int rw, int rl, int rc);
	void	addDegree(FemaleRecord& fr);	//���ÿһ�����û�������Ů�û�����������ȡ��������Լ�¼�ܱ�δ����
	void	vote(FemaleRecord& fr);						//�������û�����Ů���û�����һ��ͶƱ           
	

protected:
	vector<male_data>	m_maleRecord;
};

