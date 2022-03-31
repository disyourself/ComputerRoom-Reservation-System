#pragma once
#include "Identity.h"
#include"computerRoom.h"
#include"orderFile.h"

class Student :public Identity
{
public:
	//默认构造
	Student();

	//有参构造
	Student(int id, string name, string pwd);

	//菜单界面
	void openMenu();

	//申请预约
	void applyOrder();

	//查看我的预约
	void checkMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

private:

	//学生界面
	void studentMenu();

public:

	int m_Id;

	vector<computerRoom>vCopRoom;	//机房容器

};

