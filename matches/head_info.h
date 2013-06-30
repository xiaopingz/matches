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
	vector<int>		m_candidate;	//给女方投票的男士，只记录男士的ID，满意度临时计算，因为只需要取满意度最大的就配对成功，然后删除此对。
}female_data;