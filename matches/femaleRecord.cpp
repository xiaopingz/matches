#include "femaleRecord.h"


femaleRecord::femaleRecord(void)
{
}

femaleRecord::femaleRecord(person_info femaleInfo)
{
	female_data	fd;
	fd.m_femaleInfo		=	femaleInfo;
	m_femaleRecord.push_back(fd);
}


femaleRecord::~femaleRecord(void)
{
}
