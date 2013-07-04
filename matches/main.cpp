
#include<iostream>
//#include<memory>
#include<vector>
#include"PersonInfo.h"
#include"maleRecord.h"
#include"femaleRecord.h"
#include<fstream>
using std::ifstream;
using std::ofstream;

int main()
{
	/*auto p	=	std::make_shared<PersonInfo>(-1,80,79,95,30,55,15);
	typedef std::shared_ptr<PersonInfo> personInfo_ptr;
	std::vector<personInfo_ptr> vp;
	vp.push_back(p);
	personInfo_ptr pRead	=	*vp.begin();
	pRead->showInfo();*/

	FemaleRecord	fmr;
	MaleRecord		mr;
	ifstream fFilePlayer("../players.txt"),fFileMale("../male.txt"),fFileFemale("../female.txt");
	ofstream fFileMatchedStore("../matched.txt");

	//读取文件，生成初始信息。
	int gender,id,w,l,c,rw,rl,rc;
	char t;
	fFilePlayer>>gender>>t>>w>>t>>l>>t>>c>>t>>rw>>t>>rl>>t>>rc;
	if(gender==1)
	{
		mr.addMaleRecord(-1,w,l,c,rw,rl,rc);
		for( int i=0;i<99;++i)
		{
			fFileMale>>id>>t>>w>>t>>l>>t>>c>>t>>rw>>t>>rl>>t>>rc;
			mr.addMaleRecord(id,w,l,c,rw,rl,rc);
			fFileFemale>>id>>t>>w>>t>>l>>t>>c>>t>>rw>>t>>rl>>t>>rc;
			fmr.addFemaleRecord(id,w,l,c,rw,rl,rc);
		}
		fFileFemale>>id>>t>>w>>t>>l>>t>>c>>t>>rw>>t>>rl>>t>>rc;
		fmr.addFemaleRecord(id,w,l,c,rw,rl,rc);
	}
	else
	{
		fmr.addFemaleRecord(-1,w,l,c,rw,rl,rc);
		for( int i=0;i<99;++i)
		{
			fFileFemale>>id>>t>>w>>t>>l>>t>>c>>t>>rw>>t>>rl>>t>>rc;
			fmr.addFemaleRecord(id,w,l,c,rw,rl,rc);
			fFileMale>>id>>t>>w>>t>>l>>t>>c>>t>>rw>>t>>rl>>t>>rc;
			mr.addMaleRecord(id,w,l,c,rw,rl,rc);
		}
		fFileMale>>id>>t>>w>>t>>l>>t>>c>>t>>rw>>t>>rl>>t>>rc;
		mr.addMaleRecord(id,w,l,c,rw,rl,rc);
	}

	mr.addDegree(fmr);
	
	for(int i = 0;i<100;++i)
	{
		//一趟配对
		mr.vote(fmr);
		vector<female_data>::iterator itHot	=	fmr.getHotest();
		int idMan	=	fmr.getMatchedId(itHot,mr);
		(fmr.getHotest())->m_femaleInfo.storeInfo(fFileMatchedStore);
		mr.getElementById(idMan).m_maleInfo.storeInfo(fFileMatchedStore);
		fFileMatchedStore<<std::endl;
		fmr.deleteMatched(itHot,idMan,mr);
	}
		
	fFilePlayer.close();
	fFileFemale.close();
	fFileMale.close();
	fFileMatchedStore.close();
}