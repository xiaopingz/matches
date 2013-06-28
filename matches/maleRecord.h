#pragma once
#include"head_info.h"


class maleRecord
{
public:
	maleRecord(void);
	maleRecord(person_info maleInfo);
	~maleRecord(void);

public:
	//functions

protected:
	vector<male_data>	m_maleRecord;
};

