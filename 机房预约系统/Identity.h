#pragma once
#include<iostream>
using namespace std;

#include<string>
#include"globalFile.h"
#include<vector>

/*
	����һ����ݻ��� �������
	ʹ����ʦ��ѧ��������Ա������ͨ������ӿڽ����Լ��Ĳ˵�
*/

class Identity{
public:
	//���麯��	�����˵�
	virtual void openMenu() = 0;

	string m_Name;
	string m_Passwod;
};