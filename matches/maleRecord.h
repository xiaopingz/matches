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
	void	addDegree(FemaleRecord& fr);	//���ÿһ�����û�������Ů�û�����������ȡ��������Լ�¼�ܱ�δ����
	void	vote(FemaleRecord& fr);						//�������û�����Ů���û�����һ��ͶƱ   
	void	deleteCandidate(int idMale,int idFemale);	//�������û�����Ͷ��Ʊ��Ů�û���id,ɾ����Ӧ�����ݡ�
	void	deleteMaleRecord(int idMaleMatched);		//ɾ������Գɹ���������Ϣ 
	

protected:
	vector<male_data>	m_maleRecord;
};

