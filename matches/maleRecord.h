#pragma once
#include"head_info.h"
#include"femaleRecord.h"

class maleRecord
{
public:
	maleRecord(void);
	~maleRecord(void);

public:
	//functions
	void	addMaleRecord(int id, int wealth, int look, int charactor, int rw, int rl, int rc);
	void	addDegree(femaleRecord fr);	//针对每一个男用户，遍历女用户表，计算满意度。生成男性记录总表（未排序）
	//void	sortByDegree();				//针对每一个男用户，对其每个女性用户的满意度进行排序，方便后面的投票操作。
	void	vote(femaleRecord fr);						//遍历男用户表，对女性用户进行一次投票           
	

protected:
	vector<male_data>	m_maleRecord;
};

