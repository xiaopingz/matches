#include"personInfo.h"
#include<map>
#include<vector>
using std::vector;
using std::multimap;

typedef struct _MALE_DATA{
	personInfo		m_maleInfo;		//male person basic information
	multimap<int,int>	m_candidate;	//every female's satisfied degree
}male_data;

typedef struct _FEMALE_DATA{
	personInfo		m_femaleInfo;
	vector<int>		m_candidate;	//��Ů��ͶƱ����ʿ��ֻ��¼��ʿ��ID���������ʱ���㣬��Ϊֻ��Ҫȡ��������ľ���Գɹ���Ȼ��ɾ���˶ԡ�
}female_data;