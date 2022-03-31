//机房预约系统
/*

学生 教师 管理员 3个身份


1、2、3号 3个机房


申请订单 月月未来一周内 1-5 上午/下午 分时段

	1.登陆界面，选择身份
	2.密码验证
	3.	学生:申请预约,查看自身预约状态，查看所有预约,取消预约，
		老师：查看所有预约，审核预约，
		管理员：添加账号，查看账号，查看机房，清空预约
	注销登录


预约状态：成功、失败、审核中、取消取悦

机房信息：编号 、最大容量

*/


/*
2022.3.28	完成Adminiser::showPerson()的实现 
		todo: 查看机房
2020.3.30   完成Student::applyOrder()实现
	遇见一次stackover flow；原因是openMenu中while ture:openMenu
		todo: 创建预约类

20222.4.1	完成Student::showMyOrder->showAllOrder->CancelOrder
			BUG:1-不能取消所有的预约
				2-取消预约后status为0 但是showMyOrder不能中status无法读取
		todo:Stuent 模块的创建
*/


#pragma once
#include<iostream>
#include<string>
using namespace std;
#include<fstream>

#include"globalFile.h"
#include"Identity.h"
#include"Student.h"
#include"Teacher.h"
#include"Administer.h"

void LoginIn(string fileName, int type);



int main() {
	
	while (true) {
		int loginSelect = 0;

		cout << "-----------------------------" << endl;
		cout << "欢迎使用机房预约系统：" << endl;
		cout << "  请登录：" << endl;
		cout << "  1-学生" << endl;
		cout << "  2-老师" << endl;
		cout << "  3-管理员" << endl;
		cout << "  0-退出系统" << endl;
		cout << "------------------------------" << endl;
		
		cin >> loginSelect;

		switch (loginSelect)
		{
		case 1:	//学生
			LoginIn(STUDENT_FILE, loginSelect);
			break;
		case 2:	//老师
			LoginIn(TEACHER_FILE, loginSelect);
			break;
		case 3:	//管理员
			LoginIn(ADMIN_FILE, loginSelect);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}





void LoginIn(string fileName, int type) {
	
	//父类指针 用于指向子类
	Identity* person = NULL;
	
	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open()) {
		cout << "文件缺失(不存在)!" << endl;
		ifs.close();
		return;
	}

	//准备接收用户的信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1) {
		//学生
		cout << "请输入你的学号:" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "请输入您的职工号:" << endl;
		cin >> id;
	}

	cout << "请输入用户名:" << endl;
	cin >> name;
	cout << "请输入密码:" << endl;
	cin >> pwd;


	//身份验证
	if (type == 1) {	//学生
		
		int fId; //文件获取的id号
		string fName;
		string fPwd;

		//读到空格停止读下一个
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//与用户输入的信息对比(验证)
			if (fId == id && fName == name && fPwd == pwd) {
				cout<<"学生登录成功!"<<endl;
				system("pause");
				system("cls");
				
				person =new Student(id, name, pwd);
				
				//进入学生身份子菜单
				person->openMenu();
				
				
				return;
			}	
		}
	}
	else if (type == 2) {	//老师

		int fId; //文件获取的id号
		string fName;
		string fPwd;

		//读到空格停止读下一个
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//与用户输入的信息对比(验证)
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "教师登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				//进入教师子菜单

				return;
			}
		}
	}
	else if (type == 3) {	//管理员
		string fName;
		string fPwd;

		//读到空格停止读下一个 读完换行
		while (ifs >> fName && ifs >> fPwd)
		{
			//与用户输入的信息对比(验证)
			if (fName == name && fPwd == pwd) {
				cout << "管理员登录成功!" << endl;
				system("pause");
				system("cls");

				person = new Administer(name, pwd);

				//进入管理员菜单
				person->openMenu();

				return;
			}
		}
	}

	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");
	return;

}