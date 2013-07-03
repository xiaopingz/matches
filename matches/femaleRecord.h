#pragma once
#include"MaleRecord.h"
#include"head_info.h"


class FemaleRecord
{
public:
	FemaleRecord(void);
	~FemaleRecord(void);

public:
	//functions
	void	addFemaleRecord(int id, int wealth, int look, int charactor, int rw, int rl, int rc);
	vector<female_data>::size_type		size();		//求女士总人数
	female_data		getElement(vector<female_data>::size_type i);	//从表中获得i位置的女性用户
	female_data		getElementById(int usrId);	//根据女性用户ID查找用户
	int				addVoteInfo(int idToVote,int idOfVote);
	vector<female_data>::iterator	getHotest();	//获得投票最多的女性
	int				getMatchedId( vector<female_data>::iterator it, MaleRecord& mr );	//对投票最多的女性选择一个男性配对,return the ID of the man
	void			deleteMatched( vector<female_data>::iterator it, int idMaleMatched, MaleRecord& mr );	//删除已配对的相关所有信息。

protected:
	vector<female_data>	m_femaleRecord;
};

