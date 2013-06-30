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
		male_data md	=	m_maleRecord[i];	//��ȡһ�������û�Ԫ��
		multimap<int,int>	mmCandidate	=	md.m_candidate;	//�õ��������û���Ů�Ե������map	
		multimap<int,int>::iterator	im	=	--mmCandidate.end();	//��ȡ���һ��Ԫ�صĵ������������������Ԫ�أ�
		multimap<int,int>::size_type ix	=	mmCandidate.count((*im).first);	//��ѯ������ȵ�Ԫ���м���
		if( ix==1 )
		{
			int	voteId	=	(*im).second;	//ҪͶƱ��Ůʿ��ID
			fr.addVoteInfo(voteId);			//��Ůʿ��Ϣ���и�IDŮʿͶƱ
		}
	}
}