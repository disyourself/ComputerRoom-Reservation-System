#include "Student.h"

Student::Student()
{
}

Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Passwod = pwd;
}

void Student::openMenu()
{
	cout << "欢迎"<<this->m_Name<<"同学登录系统" << endl;
	cout << "-----------------------------" << endl;
	cout << "请选择你的操作：" << endl;
	cout << "  1-申请预约" << endl;
	cout << "  2-查看自身预约" << endl;
	cout << "  3-查看所有预约" << endl;
	cout << "  4-取消预约" << endl;
	cout << "  0-注销登录" << endl;
	cout << "------------------------------" << endl;
}

void Student::applyOrder()
{
}

void Student::checkMyOrder()
{
}

void Student::showAllOrder()
{
}

void Student::cancelOrder()
{
}
