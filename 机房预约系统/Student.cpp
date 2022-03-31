#include "Student.h"
#include<fstream>

Student::Student()
{
}

Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Passwod = pwd;

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	
	computerRoom c;
	while (ifs >> c.m_CopId && ifs >> c.maxNum) {
		vCopRoom.push_back(c);
	}
	ifs.close();

}

void Student::openMenu()
{
	
	while (true)
	{
		this->studentMenu();

		int sSelect;
		cin >> sSelect;

		switch (sSelect)
		{
		case 1:		//����ԤԼ
			cout << "����ԤԼ:" << endl;
			this->applyOrder();
			break;
		case 2:		//�鿴����ԤԼ
			cout << "�鿴����ԤԼ:" << endl;
			this->checkMyOrder();
			break;
		case 3:		//�鿴����ԤԼ
			cout << "�鿴����ԤԼ:" << endl;
			this->showAllOrder();
			break;
		case 4:		//ȡ��ԤԼ
			cout << "ȡ��ԤԼ:" << endl;
			this->cancelOrder();
			break;
		case 0:		//ע���˳�
			delete this;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "��Ч����!����������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void Student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ������" << endl;
	cout << "--��������ҪԤԼ��ʱ��:" << endl;
	cout << "1|2|3|4|5(��һ������)" << endl;

	int aoDay = 0;		//����
	int interval = 0;	//ʱ���
	int room = 0;		//�������
	
	while (true) {
		cin >> aoDay;
		if (aoDay >= 1 && aoDay <= 5) break;
		cout << "��������,����������" << endl;
	}

	cout << "����������ԤԼ��ʱ��:" << endl;
	cout << "1-����" << endl << "2-����" << endl;

	while (true)
	{
		cin >> interval;
		if (interval == 1 || interval == 2) break;
		cout << "������������������" << endl;
	}

	cout << "������ԤԼ�Ļ�����:" << endl;
	cout << "1~3" << endl;

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3) break;
		cout << "������������������" << endl;
	}

	cout << "ԤԼ�ɹ��������" << endl;


	system("pause");
	system("cls");

	ofstream ofs;
	
	//�ļ�д��ԤԼ��Ϣ
	ofs.open(ORDER_FILE, ios::out | ios::app);

	ofs << "date:"<<aoDay << " " 
		<< "interval:"<<interval << " " 
		<<"stuId:"<<this->m_Id << " "
		<<"stuName:"<<this->m_Name<<" "
		<<"roomId:"<< room << " "
		<<"status:"<<1<<endl;
	
	ofs.close();


}

void Student::checkMyOrder()
{
	orderFile oF;

	if (oF.m_Size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < oF.m_Size; i++) {
		//string תΪ int
		//if (stoi(oF.mOrderF[i]["stuId"]) == this->m_Id) {
		if(atoi(oF.mOrderF[i]["stuId"].c_str())==this->m_Id){
			//�ҵ��������ԤԼ
			cout << "ԤԼ����: ��" << oF.mOrderF[i]["date"];
			cout << " ʱ���: " << (oF.mOrderF[i]["date"]=="1"?"����":"����");
			cout << " ������: " << oF.mOrderF[i]["roomId"];
			string status = " ״̬: ";
			//1-ʢ���� 2 ��ԤԼ -1 ԤԼʧ�� 0 ȡ��ԤԼ
			if (oF.mOrderF[i]["status"] == "1") {
				status += "�����";
			}
			else if (oF.mOrderF[i]["status"] == "2") {
				status += "ԤԼ�ɹ�";
			}
			else if (oF.mOrderF[i]["status"] == "-1") {
				status += "ԤԼʧ��,���δͨ��";
			}
			else if (oF.mOrderF[i]["status"] == "0") {
				status += "ȡ��ԤԼ";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}

void Student::showAllOrder()
{
	orderFile oF;
	if (oF.m_Size == 0) {
		cout << "ԤԼ��¼Ϊ��" << endl;
		return;
	}

	for (int i = 0; i < oF.m_Size; i++) {
		cout << "ԤԼ����: ��" << oF.mOrderF[i]["date"];
		cout << " ʱ���: " << (oF.mOrderF[i]["date"] == "1" ? "����" : "����");
		cout << " ������: " << oF.mOrderF[i]["roomId"];

		cout << " ѧ��: " << oF.mOrderF[i]["stuId"];
		cout << " ������ " << oF.mOrderF[i]["stuName"];


		string status = " ״̬: ";
		//1-ʢ���� 2 ��ԤԼ -1 ԤԼʧ�� 0 ȡ��ԤԼ
		if (oF.mOrderF[i]["status"] == "1") {
			status += "�����";
		}
		else if (oF.mOrderF[i]["status"] == "2") {
			status += "ԤԼ�ɹ�";
		}
		else if (oF.mOrderF[i]["status"] == "-1") {
			status += "ԤԼʧ��,���δͨ��";
		}
		else if (oF.mOrderF[i]["status"] == "0") {
			status += "ȡ��ԤԼ";
		}
		cout << status << endl;
	}
}

void Student::cancelOrder()
{
	orderFile oF;
	if (oF.m_Size == 0) {
		cout << "ԤԼ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ��,������ȡ���ļ�¼:" << endl;
	cout << "___________________________________" << endl;

	vector<int>v;		//�������������е��±���;
	int index = 1;
	for (int i = 0; i < oF.m_Size; i++) {
		if (atoi(oF.mOrderF[i]["stuId"].c_str()) == this->m_Id) {
			//ɸѡ״̬ ����л�ԤԼ�ɹ�
			if (oF.mOrderF[i]["status"] == "1" || oF.mOrderF[i]["status"] == "2") {


				//��vector�����map��keyֵ
				v.push_back(i);


				cout << index++ << " ";
				cout << "ԤԼ����: " << oF.mOrderF[i]["date"];
				cout << "ʱ���: " << (oF.mOrderF[i]["interval"] == "1"? "����":"����");
				cout << "������: " << oF.mOrderF[i]["roomId"];
				
				string status = " ״̬: ";
				if (oF.mOrderF[i]["status"] == "1") {
					status += "�����";
				}
				else if (oF.mOrderF[i]["status"] == "2") {
					status += "ԤԼ�ɹ�";
				}

				cout << status << endl;
			}
		}
	}


	int ccSelect = 0;
	while (true)
	{
		cin >> ccSelect;
		if (ccSelect >= 0 && ccSelect <= v.size()) {
			if (ccSelect == 0)
				//0 �˳�ɾ������
				break;
			else {
				//v[ccSelect-1]
				oF.mOrderF[v[ccSelect - 1]]["satus"] = "0";

				cout << "ȡ��ԤԼ�ɹ���" << endl;
				//��дorderFile�ļ�
				//д���޸ĺ����Ϣ
				oF.updateOrder();
				break;
			}
		}
		
		cout << "��������,����������";
	}

	system("pause");
	system("cls");
}

void Student::studentMenu()
{
	cout << "��ӭ" << this->m_Name << "ͬѧ��¼ϵͳ" << endl;
	cout << "-----------------------------" << endl;
	cout << "��ѡ����Ĳ�����" << endl;
	cout << "  1-����ԤԼ" << endl;
	cout << "  2-�鿴����ԤԼ" << endl;
	cout << "  3-�鿴����ԤԼ" << endl;
	cout << "  4-ȡ��ԤԼ" << endl;
	cout << "  0-ע����¼" << endl;
	cout << "------------------------------" << endl;
}
