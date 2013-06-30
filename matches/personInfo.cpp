#include "personInfo.h"
#include<iostream>

personInfo::personInfo(void)
{
}

personInfo::personInfo(int id, int wealth, int look, int charactor, int rw, int rl, int rc)
	:m_userID(id),m_info_wealth(wealth),m_info_look(look),m_info_charactor(charactor),m_ratio_wealth(rw),m_ratio_look(rl),m_ratio_charactor(rc)
{
}

personInfo::~personInfo(void)
{
}

void	personInfo::showInfo()
{
	std::cout<<"ID:"<<m_userID<<" INFO:"<<m_info_wealth<<","<<m_info_look<<","<<m_info_charactor<<" EXPERCT:"<<m_ratio_wealth<<","<<m_ratio_look<<","<<m_ratio_charactor<<std::endl;
}

void	personInfo::assign(int id, int wealth, int look, int charactor, int rw, int rl, int rc)
{
	m_userID		=	id;
	m_info_wealth	=	wealth;		
	m_info_look		=	look;		
	m_info_charactor	=charactor;
	m_ratio_wealth	=	rw;
	m_ratio_look	=	rl;
	m_ratio_charactor	=	rc;
}

int		personInfo::calculateDegree(personInfo target)
{
	int satisfiedDegree	= m_info_wealth * target.getRW() + m_info_look * target.getRL() + m_info_charactor * target.getRC();
	return	satisfiedDegree;
}

int		personInfo::getUsrID()
{
	return	m_userID;
}

int personInfo::getRW()
{
	return	m_ratio_wealth;
}

int personInfo::getRL()
{
	return	m_ratio_look;
}

int personInfo::getRC()
{
	return	m_ratio_charactor;
}