#pragma once
#include"head_info.h"
 class FemaleRecord;

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
	void	deleteCandidate(int idMale,int idFemale);	//给出男用户与其投过票的女用户的id,删除对应的数据。
	void	deleteMaleRecord(int idMaleMatched);		//删除已配对成功的男性信息 
	

protected:
	vector<male_data>	m_maleRecord;
};

