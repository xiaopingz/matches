#include "maleRecord.h"


maleRecord::maleRecord(void)
{
}

maleRecord::maleRecord(person_info maleInfo)
{
	male_data	md;
	md.m_maleInfo	=	maleInfo;
	m_maleRecord.push_back(md);
}

maleRecord::~maleRecord(void)
{
}
