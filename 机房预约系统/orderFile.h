#pragma once

#include<map>
#include<string>
#include<fstream>
#include"globalFile.h"
#include<iostream>

using namespace std;

class orderFile
{
public:

	orderFile();

	//����ԤԼ��¼
	void updateOrder();

	//��ȡ�ļ���ȡkey��value����map
	void insertMap(string &data,map<string,string>&m);



	int m_Size;				//��¼ԤԼ����
	map<int, map<string, string>>mOrderF;	//ԤԼ��¼������
};

