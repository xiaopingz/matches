#include "PersonInfo.h"
#include<iostream>

PersonInfo::PersonInfo(void)
{
}

PersonInfo::PersonInfo(int id, int wealth, int look, int charactor, int rw, int rl, int rc)
	:m_userID(id),m_info_wealth(wealth),m_info_look(look),m_info_charactor(charactor),m_ratio_wealth(rw),m_ratio_look(rl),m_ratio_charactor(rc)
{
}

PersonInfo::~PersonInfo(void)
{
}

void	PersonInfo::showInfo()
{
	std::cout<<"ID:"<<m_userID<<" INFO:"<<m_info_wealth<<","<<m_info_look<<","<<m_info_charactor<<" EXPERCT:"<<m_ratio_wealth<<","<<m_ratio_look<<","<<m_ratio_charactor<<std::endl;
}

void	PersonInfo::storeInfo(ofstream& fs)
{
	fs<<"ID:"<<m_userID<<" INFO:"<<m_info_wealth<<","<<m_info_look<<","<<m_info_charactor<<" EXPERCT:"<<m_ratio_wealth<<","<<m_ratio_look<<","<<m_ratio_charactor;
}

void	PersonInfo::assign(int id, int wealth, int look, int charactor, int rw, int rl, int rc)
{
	m_userID		=	id;
	m_info_wealth	=	wealth;		
	m_info_look		=	look;		
	m_info_charactor	=charactor;
	m_ratio_wealth	=	rw;
	m_ratio_look	=	rl;
	m_ratio_charactor	=	rc;
}

int		PersonInfo::calculateDegree(PersonInfo target)
{
	int satisfiedDegree	= m_info_wealth * target.getRW() + m_info_look * target.getRL() + m_info_charactor * target.getRC();
	return	satisfiedDegree;
}

int		PersonInfo::sumOfInfo()
{
	return m_info_charactor+m_info_look+m_info_wealth;
}

int		PersonInfo::getUsrID()
{
	return	m_userID;
}

int PersonInfo::getRW()
{
	return	m_ratio_wealth;
}

int PersonInfo::getRL()
{
	return	m_ratio_look;
}

int PersonInfo::getRC()
{
	return	m_ratio_charactor;
}