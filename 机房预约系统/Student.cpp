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
	cout << "��ӭ"<<this->m_Name<<"ͬѧ��¼ϵͳ" << endl;
	cout << "-----------------------------" << endl;
	cout << "��ѡ����Ĳ�����" << endl;
	cout << "  1-����ԤԼ" << endl;
	cout << "  2-�鿴����ԤԼ" << endl;
	cout << "  3-�鿴����ԤԼ" << endl;
	cout << "  4-ȡ��ԤԼ" << endl;
	cout << "  0-ע����¼" << endl;
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
