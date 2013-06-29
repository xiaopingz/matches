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
	vector<female_data>::size_type		size();
	female_data	getElement(vector<female_data>::size_type i);			

protected:
	vector<female_data>	m_femaleRecord;
};

