#include "maleRecord.h"


maleRecord::maleRecord(void)
{
}

maleRecord::~maleRecord(void)
{
}

void	maleRecord::addMaleRecord(int id, int wealth, int look, int charactor, int rw, int rl, int rc)
{
	male_data	maleData;
	maleData.m_maleInfo.assign(id,wealth,look,charactor,rw,rl,rc);
}

void	maleRecord::addDegree(femaleRecord fr)
{
	for(vector<male_data>::size_type i = 0;i!=m_maleRecord.size();++i)
	{
		for(vector<female_data>::size_type j = 0;j!=fr.size();++j)
		{
			int	usrId	=	fr.getElement(j).m_femaleInfo.getUsrID();
			int	degree	=	m_maleRecord[i].m_maleInfo.calculateDegree(fr.getElement(j).m_femaleInfo);
			m_maleRecord[i].m_candidate[usrId]	=	degree;
		}
	}
}

void	maleRecord::sortByDegree()
{
	for(vector<male_data>::size_type i = 0;i!=m_maleRecord.size();++i)
	{

	}
}

void	maleRecord::vote()
{
}