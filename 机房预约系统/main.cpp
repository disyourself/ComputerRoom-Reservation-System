//����ԤԼϵͳ
/*

ѧ�� ��ʦ ����Ա 3�����


1��2��3�� 3������


���붩�� ����δ��һ���� 1-5 ����/���� ��ʱ��

	1.��½���棬ѡ�����
	2.������֤
	3.	ѧ��:����ԤԼ,�鿴����ԤԼ״̬���鿴����ԤԼ,ȡ��ԤԼ��
		��ʦ���鿴����ԤԼ�����ԤԼ��
		����Ա������˺ţ��鿴�˺ţ��鿴���������ԤԼ
	ע����¼


ԤԼ״̬���ɹ���ʧ�ܡ�����С�ȡ��ȡ��

������Ϣ����� ���������

*/


/*
2022.3.28	���Adminiser::showPerson()��ʵ�� 
		todo: �鿴����
2020.3.30   ���Student::applyOrder()ʵ��
	����һ��stackover flow��ԭ����openMenu��while ture:openMenu
		todo: ����ԤԼ��

20222.4.1	���Student::showMyOrder->showAllOrder->CancelOrder
			BUG:1-����ȡ�����е�ԤԼ
				2-ȡ��ԤԼ��statusΪ0 ����showMyOrder������status�޷���ȡ
		todo:Stuent ģ��Ĵ���
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
		cout << "��ӭʹ�û���ԤԼϵͳ��" << endl;
		cout << "  ���¼��" << endl;
		cout << "  1-ѧ��" << endl;
		cout << "  2-��ʦ" << endl;
		cout << "  3-����Ա" << endl;
		cout << "  0-�˳�ϵͳ" << endl;
		cout << "------------------------------" << endl;
		
		cin >> loginSelect;

		switch (loginSelect)
		{
		case 1:	//ѧ��
			LoginIn(STUDENT_FILE, loginSelect);
			break;
		case 2:	//��ʦ
			LoginIn(TEACHER_FILE, loginSelect);
			break;
		case 3:	//����Ա
			LoginIn(ADMIN_FILE, loginSelect);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "������������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}





void LoginIn(string fileName, int type) {
	
	//����ָ�� ����ָ������
	Identity* person = NULL;
	
	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open()) {
		cout << "�ļ�ȱʧ(������)!" << endl;
		ifs.close();
		return;
	}

	//׼�������û�����Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1) {
		//ѧ��
		cout << "���������ѧ��:" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "����������ְ����:" << endl;
		cin >> id;
	}

	cout << "�������û���:" << endl;
	cin >> name;
	cout << "����������:" << endl;
	cin >> pwd;


	//�����֤
	if (type == 1) {	//ѧ��
		
		int fId; //�ļ���ȡ��id��
		string fName;
		string fPwd;

		//�����ո�ֹͣ����һ��
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//���û��������Ϣ�Ա�(��֤)
			if (fId == id && fName == name && fPwd == pwd) {
				cout<<"ѧ����¼�ɹ�!"<<endl;
				system("pause");
				system("cls");
				
				person =new Student(id, name, pwd);
				
				//����ѧ������Ӳ˵�
				person->openMenu();
				
				
				return;
			}	
		}
	}
	else if (type == 2) {	//��ʦ

		int fId; //�ļ���ȡ��id��
		string fName;
		string fPwd;

		//�����ո�ֹͣ����һ��
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//���û��������Ϣ�Ա�(��֤)
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "��ʦ��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				//�����ʦ�Ӳ˵�

				return;
			}
		}
	}
	else if (type == 3) {	//����Ա
		string fName;
		string fPwd;

		//�����ո�ֹͣ����һ�� ���껻��
		while (ifs >> fName && ifs >> fPwd)
		{
			//���û��������Ϣ�Ա�(��֤)
			if (fName == name && fPwd == pwd) {
				cout << "����Ա��¼�ɹ�!" << endl;
				system("pause");
				system("cls");

				person = new Administer(name, pwd);

				//�������Ա�˵�
				person->openMenu();

				return;
			}
		}
	}

	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;

}