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
	vector<female_data>::size_type		size();		//求女士总人数
	female_data	getElement(vector<female_data>::size_type i);	//从表中获得i位置的女性用户
	int			addVoteInfo(int idToVote);

protected:
	vector<female_data>	m_femaleRecord;
};

