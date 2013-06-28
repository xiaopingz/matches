#include<map>
#include<vector>
using std::vector;
using std::map;


typedef struct _PERSON_INFO_RECORD{
	int m_userID;
	int m_info_wealth;		//���˲Ƹ�: ȡֵ1~100
	int m_info_look;		//������ò��ȡֵ1~100
	int m_info_charactor;	//����Ʒ��ȡֵ1~100
	int m_ratio_wealth;
	int m_ratio_look;
	int m_ratio_charactor;	//����ż����ָ��������ٷֱȣ����ߺ�Ϊ100������ȡֵ1~98
}person_info;

typedef struct _MALE_DATA{
	person_info		m_maleInfo;		//male person basic information
	map<int,int>	m_candidate;	//every female's satisfied degree
}male_data;

typedef struct _FEMALE_DATA{
	person_info		m_femaleInfo;
	vector<int>		m_candidate;	//��Ů��ͶƱ����ʿ��ֻ��¼��ʿ��ID���������ʱ���㣬��Ϊֻ��Ҫȡ��������ľ���Գɹ���Ȼ��ɾ���˶ԡ�
}female_data;