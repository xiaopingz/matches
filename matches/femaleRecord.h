#pragma once
#include"head_info.h"

class femaleRecord
{
public:
	femaleRecord(void);
	~femaleRecord(void);

public:
	//functions
	void	addFemaleRecord(int id, int wealth, int look, int charactor, int rw, int rl, int rc);
	vector<female_data>::size_type		size();		//��Ůʿ������
	female_data	getElement(vector<female_data>::size_type i);	//�ӱ��л��iλ�õ�Ů���û�
	int			addVoteInfo(int idToVote);

protected:
	vector<female_data>	m_femaleRecord;
};

