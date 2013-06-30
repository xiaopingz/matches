#pragma once
class personInfo
{
public:
	personInfo(void);
	personInfo(int id,int wealth,int look,int charactor,int rw,int rl, int rc);
	~personInfo(void);

public:
	void	showInfo();
	void	assign(int id, int wealth, int look, int charactor, int rw, int rl, int rc);
	int		calculateDegree(personInfo target);	//计算单个满意度，参数为被计算的对象
	int		getUsrID();
	int		getRW();	//获取期望对象的对应参数的比例
	int		getRL();
	int		getRC();

protected:
	int m_userID;
	int m_info_wealth;		//本人财富: 取值1~100
	int m_info_look;		//本人样貌：取值1~100
	int m_info_charactor;	//本人品格：取值1~100
	int m_ratio_wealth;
	int m_ratio_look;
	int m_ratio_charactor;	//对配偶三项指标的期望百分比，三者和为100，各自取值1~98
};

