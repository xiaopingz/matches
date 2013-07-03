#include "FemaleRecord.h"


FemaleRecord::FemaleRecord(void)
{
}

FemaleRecord::~FemaleRecord(void)
{
}

void	FemaleRecord::addFemaleRecord(int id, int wealth, int look, int charactor, int rw, int rl, int rc)
{
	female_data	femaleData;
	femaleData.m_femaleInfo.assign(id,wealth,look,charactor,rw,rl,rc);
	m_femaleRecord.push_back(femaleData);
}

vector<female_data>::size_type FemaleRecord::size()
{
	return m_femaleRecord.size();
}

female_data	FemaleRecord::getElement(vector<female_data>::size_type i)
{
	return m_femaleRecord[i];
}

female_data	FemaleRecord::getElementById(int usrId)
{
	for(vector<female_data>::size_type i = 0;i!=m_femaleRecord.size();++i)
	{
		if( m_femaleRecord[i].m_femaleInfo.getUsrID() == usrId )
			return m_femaleRecord[i];
	}
}

int			FemaleRecord::addVoteInfo(int idToVote,int idOfVote)
{
	vector<female_data>::size_type ix;
	for( ix = 0;ix!=m_femaleRecord.size();++ix)
	{
		PersonInfo	fpi	=	m_femaleRecord[ix].m_femaleInfo;
		if(fpi.getUsrID() == idToVote)
		{
			m_femaleRecord[ix].m_candidate.push_back(idOfVote);
			return 1;
		}
	}
	if( ix==m_femaleRecord.size() )
		return 0;
}

vector<female_data>::iterator	FemaleRecord::getHotest()
{
	vector<female_data>::iterator	iter,	itMax;
	vector<int>::size_type			szMax=0,	szTmp;
	for( iter=m_femaleRecord.begin();iter!=m_femaleRecord.end();++iter )
	{
		szTmp	=	(iter->m_candidate).size();
		if( szTmp>szMax )
		{
			szMax	=	szMax;
			itMax	=	iter;
		}
	}
	return itMax;
}

int		FemaleRecord::getMatchedId( vector<female_data>::iterator it, MaleRecord& mr )
{
	vector<int>		vCandidate	=	it->m_candidate;
	vector<int>::size_type ix=0;
	int idOfMax, idNow, idMin;	
	int degree, degreeMax=0;
	int sumNow, sumMax;
	for( ;ix<vCandidate.size();++ix )
	{
		idNow	=	vCandidate[ix];
		degree	=	it->m_femaleInfo.calculateDegree( mr.getElementById(idNow).m_maleInfo);
		if( degree>degreeMax )
		{
			idOfMax	=	idNow;
			idMin	=	idNow;
			sumMax	=	mr.getElementById(idNow).m_maleInfo.sumOfInfo();
		}
		if( degree==degreeMax )
		{
			int sumNow	=	mr.getElementById(idNow).m_maleInfo.sumOfInfo();
			if(sumNow>sumMax)
			{
				idOfMax	=	idNow;
			}
			if(sumNow==sumMax)
			{
				if(idNow<idMin)
					idOfMax	=	idNow;
			}
		}
	}
	return	idOfMax;
}

void			FemaleRecord::deleteMatched( vector<female_data>::iterator it, int idMaleMatched, MaleRecord& mr )
{
	vector<int>		vCandidate	=	it->m_candidate;
	vector<int>::size_type ix=0;
	int		idMale,	idFemale;
	idFemale	=	it->m_femaleInfo.getUsrID();

	for( ; ix<vCandidate.size(); ++ix )
	{
		idMale	=	vCandidate[ix];
		mr.deleteCandidate(idMale,idFemale);
	}
	mr.deleteMaleRecord(idMaleMatched);
	m_femaleRecord.erase(it);

}