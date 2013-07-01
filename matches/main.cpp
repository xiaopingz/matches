
#include<iostream>
#include<memory>
#include<vector>
#include"PersonInfo.h"

int main()
{
	auto p	=	std::make_shared<PersonInfo>(-1,80,79,95,30,55,15);
	typedef std::shared_ptr<PersonInfo> personInfo_ptr;
	std::vector<personInfo_ptr> vp;
	vp.push_back(p);
	personInfo_ptr pRead	=	*vp.begin();
	pRead->showInfo();
}