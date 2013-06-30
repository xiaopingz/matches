#include "femaleRecord.h"


femaleRecord::femaleRecord(void)
{
}

femaleRecord::~femaleRecord(void)
{
}

void	femaleRecord::addFemaleRecord(int id, int wealth, int look, int charactor, int rw, int rl, int rc)
{
	female_data	femaleData;
	femaleData.m_femaleInfo.assign(id,wealth,look,charactor,rw,rl,rc);
}

vector<female_data>::size_type femaleRecord::size()
{
	return m_femaleRecord.size();
}

female_data	femaleRecord::getElement(vector<female_data>::size_type i)
{
	return m_femaleRecord[i];
}

int			femaleRecord::addVoteInfo(int idToVote)
{
	return 1;
}