#include<map>
#include<vector>
using std::vector;
using std::map;


typedef struct _PERSON_INFO_RECORD{
	int m_userID;
	int m_info_wealth;		//本人财富: 取值1~100
	int m_info_look;		//本人样貌：取值1~100
	int m_info_charactor;	//本人品格：取值1~100
	int m_ratio_wealth;
	int m_ratio_look;
	int m_ratio_charactor;	//对配偶三项指标的期望百分比，三者和为100，各自取值1~98
}person_info;

typedef struct _MALE_DATA{
	person_info		m_maleInfo;		//male person basic information
	map<int,int>	m_candidate;	//every female's satisfied degree
}male_data;

typedef struct _FEMALE_DATA{
	person_info		m_femaleInfo;
	vector<int>		m_candidate;	//给女方投票的男士，只记录男士的ID，满意度临时计算，因为只需要取满意度最大的就配对成功，然后删除此对。
}female_data;