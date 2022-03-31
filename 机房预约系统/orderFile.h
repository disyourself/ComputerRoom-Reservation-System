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

	//更新预约记录
	void updateOrder();

	//读取文件截取key和value进入map
	void insertMap(string &data,map<string,string>&m);



	int m_Size;				//记录预约条数
	map<int, map<string, string>>mOrderF;	//预约记录的条数
};

