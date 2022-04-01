#include "Teacher.h"

Teacher::Teacher()
{
}

Teacher::Teacher(int emId, string name, string pwd)
{
	this->em_Id = emId;
	this->m_Name = name;
	this->m_Passwod = pwd;
}

void Teacher::openMenu()
{
	while (true)
	{
		this->teacherMenu();

		int thSelect;
		cin >> thSelect;

		switch (thSelect)
		{

		case 1:		//查看所有预约
			this->showAllOrder();
			break;
		case 2:		//审核预约
			this->reviewOrder();
			break;
		case 0:		//注销登录
			cout << "注销登录成功" << endl;
			system("pause");
			system("cls");
			return;
			break;

		default:
			cout << "输入有误，请重新输入!" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
}

void Teacher::showAllOrder()
{
	orderFile oF;
	oF.showAllOrder();
	
}

void Teacher::reviewOrder()
{
	orderFile oF;
	if (oF.m_Size == 0) {
		cout << "预约记录为空" << endl;
		return;
	}

	vector<int>v;	//存放mOrderF 下标
	int index = 1;

	cout << "请选择要审核的预约:" << endl;
	cout << "输入0退出审核" << endl;
	cout << "-----------------------------------" << endl;

	for (int i = 0; i < oF.m_Size; i++) {
		if (oF.mOrderF[i]["status"] == "1") {

			v.push_back(i);

			cout << index << " ";
			cout << "预约日期: 周" << oF.mOrderF[i]["date"];
			cout << " 时间段: " << (oF.mOrderF[i]["date"] == "1" ? "上午" : "下午");
			cout << " 机房号: " << oF.mOrderF[i]["roomId"];

			cout << " 学号: " << oF.mOrderF[i]["stuId"];
			cout << " 姓名： " << oF.mOrderF[i]["stuName"];
			cout << " 状态： " << "审核中" << endl;
			index++;
		}
	}

	int rvSelect;
	cin >> rvSelect;
	while(true) {
		if (rvSelect >= 0 && rvSelect <= v.size()) {
			if (rvSelect == 0) {
				return;
			}
			break;
		}
		else {
			cout << "输入有误" << endl;
			system("pause");
			system("cls");
		}
	}


	cout << "请选择审核结果:" << endl;
	cout << "1-同意申请" << endl;
	cout << "2-拒绝申请"<<endl;

	int choice;
	while (true)
	{
		cin >> choice;
		if (choice ==1 || choice == 2) {
			break;
		}
		else {
			cout << "输入有误" << endl;
			system("pause");
			system("cls");
		}
	}
	
	if (choice == 1) {
		oF.mOrderF[v[rvSelect-1]]["status"] = "2";
	}
	else
	{
		oF.mOrderF[v[rvSelect - 1]]["status"] = "-1";
	}

	cout << "账号审核成功！" << endl;

	oF.updateOrder();

	system("pause");
	system("cls");


}

void Teacher::teacherMenu()
{
	cout << "-----------------------------" << endl;
	cout << "欢迎" << this->m_Name << "老师登录!" << endl;
	cout << "  1-查看所有预约" << endl;
	cout << "  2-审核预约" << endl;
	cout << "  0-退出系统" << endl;
	cout << "------------------------------" << endl;
	cout << "请选择您的操作: " << endl;
}
