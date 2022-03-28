#pragma once
#include "Identity.h"
class Teacher :public Identity
{
public:
	Teacher();

	Teacher(int emId, string name, string pwd);

	// 菜单界面
	virtual void openMenu();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void reviewOrder();


	int em_Id;
};

