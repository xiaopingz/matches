#include "MaleRecord.h"
#include"femaleRecord.h"
#include<utility>
using std::make_pair;

MaleRecord::MaleRecord(void)
{
}

MaleRecord::~MaleRecord(void)
{
}

male_data	MaleRecord::getElementById(int id)
{
	for(vector<male_data>::size_type i = 0;i!=m_maleRecord.size();++i)
	{
		if( m_maleRecord[i].m_maleInfo.getUsrID() == id )
			return m_maleRecord[i];
	}
}

void	MaleRecord::addMaleRecord(int id, int wealth, int look, int charactor, int rw, int rl, int rc)
{
	male_data	maleData;
	maleData.m_maleInfo.assign(id,wealth,look,charactor,rw,rl,rc);
	m_maleRecord.push_back(maleData);
}

void	MaleRecord::addDegree(FemaleRecord& fr)
{
	for(vector<male_data>::size_type i = 0;i!=m_maleRecord.size();++i)
	{
		for(vector<female_data>::size_type j = 0;j!=fr.size();++j)
		{
			int	usrId	=	fr.getElement(j).m_femaleInfo.getUsrID();
			int	degree	=	m_maleRecord[i].m_maleInfo.calculateDegree(fr.getElement(j).m_femaleInfo);
			m_maleRecord[i].m_candidate.insert(make_pair(degree,usrId));
		}
	}
}


void	MaleRecord::vote(FemaleRecord& fr)
{
	for(vector<male_data>::size_type i = 0;i!=m_maleRecord.size();++i)
	{
		male_data md	=	m_maleRecord[i];	//获取一个男性用户元素
		multimap<int,int>	mmCandidate	=	md.m_candidate;	//得到该男性用户对女性的满意度map	

		//获取最后一个元素的迭代器（即满意度最大的元素）
		multimap<int,int>::iterator	im	=	mmCandidate.begin();
		for( multimap<int,int>::size_type ix =0;ix<mmCandidate.size()-1;++ix)
			im++;

		multimap<int,int>::size_type ix	=	mmCandidate.count((*im).first);	//查询此满意度的元素有几个
		int		idOfVote	=	m_maleRecord[i].m_maleInfo.getUsrID();
		int		voteId		=	(*im).second;
		
		if( ix>1 )
		{	//同一个满意度对应多个女性用户，则再进行选择
			multimap<int,int>::iterator itFlag = mmCandidate.find((*im).first);	//找出满意度重复的第一个位置
			int sumMax	=	0;	//记录用户自身三个属性之和最大的
			int idMin	=	(*itFlag).second;

			for( multimap<int,int>::size_type i = 0;i<ix;++i )
			{
				int idNow	=	(*itFlag).second;
				int sumTmp = (fr.getElementById(idNow)).m_femaleInfo.sumOfInfo();
				if( sumTmp>sumMax )
				{
					sumMax = sumTmp;
					voteId = (*itFlag).second;
				}
				if( sumTmp==sumMax )
				{
					int idTmp = (*itFlag).second;
					if( idTmp<idMin )
					{
						idMin	=	idTmp;
						voteId	=	idMin;
					}
				}
				++itFlag;
			}
		}

		fr.addVoteInfo(voteId,idOfVote);			//在女士信息表中给ID女士投票
	}
}

void	MaleRecord::deleteCandidate(int idFemale)
{
	for( vector<male_data>::iterator iterVec = m_maleRecord.begin();iterVec!=m_maleRecord.end();++iterVec )
	{
		for( multimap<int,int>::iterator	im	=	iterVec->m_candidate.begin();im != iterVec->m_candidate.end();++im )
		{
			if( im->second == idFemale )
			{
				iterVec->m_candidate.erase(im);
				break;
			}
		}
	}
}

void	MaleRecord::deleteMaleRecord(int idMaleMatched)
{
	for( vector<male_data>::iterator iterVec = m_maleRecord.begin();iterVec!=m_maleRecord.end();++iterVec )
	{
		if( iterVec->m_maleInfo.getUsrID() == idMaleMatched )
		{
			m_maleRecord.erase(iterVec);
			break;
		}
	}
}