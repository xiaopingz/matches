#include "MaleRecord.h"
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
		if( m_maleRecord[i].m_maleInfo.getUsrID == id )
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
		male_data md	=	m_maleRecord[i];	//��ȡһ�������û�Ԫ��
		multimap<int,int>	mmCandidate	=	md.m_candidate;	//�õ��������û���Ů�Ե������map	
		multimap<int,int>::iterator	im	=	--mmCandidate.end();	//��ȡ���һ��Ԫ�صĵ������������������Ԫ�أ�
		multimap<int,int>::size_type ix	=	mmCandidate.count((*im).first);	//��ѯ������ȵ�Ԫ���м���
		int		idOfVote	=	m_maleRecord[i].m_maleInfo.getUsrID;
		int		voteId		=	(*im).second;
		
		if( ix>1 )
		{	//ͬһ������ȶ�Ӧ���Ů���û������ٽ���ѡ��
			multimap<int,int>::iterator itFlag = mmCandidate.find((*im).first);	//�ҳ�������ظ��ĵ�һ��λ��
			int sumMax	=	0;	//��¼�û�������������֮������
			int idMin	=	(*itFlag).second;

			for( multimap<int,int>::size_type i = 0;i<ix;++i )
			{
				int sumTmp = (fr.getElementById((*itFlag).second)).m_femaleInfo.sumOfInfo();
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

		fr.addVoteInfo(voteId,idOfVote);			//��Ůʿ��Ϣ���и�IDŮʿͶƱ
	}
}