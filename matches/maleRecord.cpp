#include "maleRecord.h"
#include<utility>
using std::make_pair;

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
			m_maleRecord[i].m_candidate.insert(make_pair(degree,usrId));
		}
	}
}

//void	maleRecord::sortByDegree()
//{
//	for(vector<male_data>::size_type i = 0;i!=m_maleRecord.size();++i)
//	{
//
//	}
//}

void	maleRecord::vote(femaleRecord fr)
{
	for(vector<male_data>::size_type i = 0;i!=m_maleRecord.size();++i)
	{
		male_data md	=	m_maleRecord[i];	//获取一个男性用户元素
		multimap<int,int>	mmCandidate	=	md.m_candidate;	//得到该男性用户对女性的满意度map	
		multimap<int,int>::iterator	im	=	--mmCandidate.end();	//获取最后一个元素的迭代器（即满意度最大的元素）
		multimap<int,int>::size_type ix	=	mmCandidate.count((*im).first);	//查询此满意度的元素有几个
		if( ix==1 )
		{
			int	voteId	=	(*im).second;	//要投票的女士的ID
			fr.addVoteInfo(voteId);			//在女士信息表中给ID女士投票
		}
	}
}