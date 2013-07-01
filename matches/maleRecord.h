#pragma once
#include"head_info.h"
#include"FemaleRecord.h"

class MaleRecord
{
public:
	MaleRecord(void);
	~MaleRecord(void);

public:
	//functions
	male_data	getElementById(int id);
	void	addMaleRecord(int id, int wealth, int look, int charactor, int rw, int rl, int rc);
	void	addDegree(FemaleRecord& fr);	//针对每一个男用户，遍历女用户表，计算满意度。生成男性记录总表（未排序）
	void	vote(FemaleRecord& fr);						//遍历男用户表，对女性用户进行一次投票           
	

protected:
	vector<male_data>	m_maleRecord;
};

