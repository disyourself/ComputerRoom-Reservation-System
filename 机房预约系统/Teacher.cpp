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

		case 1:		//�鿴����ԤԼ
			this->showAllOrder();
			break;
		case 2:		//���ԤԼ
			this->reviewOrder();
			break;
		case 0:		//ע����¼
			cout << "ע����¼�ɹ�" << endl;
			system("pause");
			system("cls");
			return;
			break;

		default:
			cout << "������������������!" << endl;
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
		cout << "ԤԼ��¼Ϊ��" << endl;
		return;
	}

	vector<int>v;	//���mOrderF �±�
	int index = 1;

	cout << "��ѡ��Ҫ��˵�ԤԼ:" << endl;
	cout << "����0�˳����" << endl;
	cout << "-----------------------------------" << endl;

	for (int i = 0; i < oF.m_Size; i++) {
		if (oF.mOrderF[i]["status"] == "1") {

			v.push_back(i);

			cout << index << " ";
			cout << "ԤԼ����: ��" << oF.mOrderF[i]["date"];
			cout << " ʱ���: " << (oF.mOrderF[i]["date"] == "1" ? "����" : "����");
			cout << " ������: " << oF.mOrderF[i]["roomId"];

			cout << " ѧ��: " << oF.mOrderF[i]["stuId"];
			cout << " ������ " << oF.mOrderF[i]["stuName"];
			cout << " ״̬�� " << "�����" << endl;
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
			cout << "��������" << endl;
			system("pause");
			system("cls");
		}
	}


	cout << "��ѡ����˽��:" << endl;
	cout << "1-ͬ������" << endl;
	cout << "2-�ܾ�����"<<endl;

	int choice;
	while (true)
	{
		cin >> choice;
		if (choice ==1 || choice == 2) {
			break;
		}
		else {
			cout << "��������" << endl;
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

	cout << "�˺���˳ɹ���" << endl;

	oF.updateOrder();

	system("pause");
	system("cls");


}

void Teacher::teacherMenu()
{
	cout << "-----------------------------" << endl;
	cout << "��ӭ" << this->m_Name << "��ʦ��¼!" << endl;
	cout << "  1-�鿴����ԤԼ" << endl;
	cout << "  2-���ԤԼ" << endl;
	cout << "  0-�˳�ϵͳ" << endl;
	cout << "------------------------------" << endl;
	cout << "��ѡ�����Ĳ���: " << endl;
}
