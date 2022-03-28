#pragma once
#include<iostream>
using namespace std;

#include<string>
#include"globalFile.h"
#include<vector>

/*
	创建一个身份基类 抽象出来
	使得老师，学生，管理员都可以通过这个接口进入自己的菜单
*/

class Identity{
public:
	//纯虚函数	操作菜单
	virtual void openMenu() = 0;

	string m_Name;
	string m_Passwod;
};