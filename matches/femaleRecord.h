#pragma once
#include"head_info.h"

class femaleRecord
{
public:
	femaleRecord(void);
	femaleRecord(person_info femaleInfo);
	~femaleRecord(void);

public:
	//functions

protected:
	vector<female_data>	m_femaleRecord;
};

