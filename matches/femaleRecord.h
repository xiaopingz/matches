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
	vector<female_data>::size_type		size();		//��Ůʿ������
	female_data		getElement(vector<female_data>::size_type i);	//�ӱ��л��iλ�õ�Ů���û�
	female_data		getElementById(int usrId);	//����Ů���û�ID�����û�
	int				addVoteInfo(int idToVote,int idOfVote);
	vector<female_data>::iterator	getHotest();	//���ͶƱ����Ů��
	int				getMatchedId( vector<female_data>::iterator it, MaleRecord& mr );	//��ͶƱ����Ů��ѡ��һ���������,return the ID of the man
	void			deleteMatched( vector<female_data>::iterator it, int idMaleMatched, MaleRecord& mr );	//ɾ������Ե����������Ϣ��

protected:
	vector<female_data>	m_femaleRecord;
};

