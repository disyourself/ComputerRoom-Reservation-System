#include "Administer.h"
#include<fstream>

Administer::Administer()
{
	this->initVector();
}

//�вι���
Administer::Administer(string name, string pwd)
{
	//��ʼ������Ա��Ϣ
	this->m_Name = name;
	this->m_Passwod = pwd;
	
	//��ʼ����������ȡ�����ļ��е���ʦ��ѧ��
	this->initVector();
}


//�βθ�ʵ�ζ���n��(1����ָ���ʱ���ββ���ָ��ʵ�Σ����Ƕ�ʵ�εĿ�����������ã����õģ��β�ָ��ʵ�Σ���Ҫ��һ������*�ţ�
//������->����.��������ĺ��� Identity *&perosn
//������this ���������
void Administer::openMenu()
{
	while (true) {
		//���ù���Ա�Ӳ˵�
		this->adminMenu();

		//������ָ��תΪ����ָ�룬����������������ӿ�
		Administer* admin = (Administer*)this;

		int _select;
		cin >> _select;

		switch (_select)
		{
		case 1:		//����˺�
			cout << "����˺�:" << endl;
			admin->addAccount();
			break;
		case 2:		//�鿴�˺�
			cout << "�鿴�˺�:" << endl;
			admin->showPerson();
			break;
		case 3:		//�鿴����
			cout << "�鿴����:" << endl;
			admin->showCopRoom();
			break;
		case 4:		//���ԤԼ
			cout << "���ԤԼ:" << endl;
			admin->clearFile();
			break;
		case 0:		//ע���˳�
			delete admin;
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


void Administer::adminMenu()
{
	cout << "-----------------------------" << endl;
	cout << "��ӭ����Ա" << this->m_Name << "��¼!" << endl;
	cout << "  1-����˺�" << endl;
	cout << "  2-�鿴�˺�" << endl;
	cout << "  3-�鿴����" << endl;
	cout << "  4-���ԤԼ" << endl;
	cout << "  0-�˳�ϵͳ" << endl;
	cout << "------------------------------" << endl;
	cout << "��ѡ�����Ĳ���: " << endl;

}

void Administer::initVector()
{
	vStudent.clear();
	vTeacher.clear();

	ifstream ifs;

//��ȡ��Ϣ ѧ��
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << STUDENT_FILE << "�ļ���ȡʧ��!" << endl;
		return;
	}

	Student s;
	//�����ո��ֹͣ ����һ��
	while (ifs>>s.m_Id&&ifs>>s.m_Name&&ifs>>s.m_Passwod){
		vStudent.push_back(s);
	}

	cout << "��ǰ��ѧ������Ϊ:" << vStudent.size() << endl;
	ifs.close();

//��ȡ��Ϣ ��ʦ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << TEACHER_FILE << "�ļ���ȡʧ��!" << endl;
		return;
	}

	Teacher t;
	//�����ո��ֹͣ ����һ��
	while (ifs >> t.em_Id && ifs >> t.m_Name && ifs >> t.m_Passwod) {
		vTeacher.push_back(t);
	}

	cout << "��ǰ����ʦ����Ϊ:" << vStudent.size() << endl;
	ifs.close();

}

bool Administer::checkRepeat(int id, int type)
{
	if (type == 1) {
		//���ѧ��
		for (vector<Student>::iterator it = vStudent.begin(); it != vStudent.end(); it++) {
			if (it->m_Id == id) return true;
		}
	}
	else{
		//�����ʦ
		for (vector<Teacher>::iterator it=vTeacher.begin(); it!=vTeacher.end(); it++){
			if (it->em_Id == id)return true;
		}
	}
	
	return false;
}



void Administer::addAccount()
{
	cout << "����������˺ŵ�����:" << endl;
	cout << "1-���ѧ��" << endl;
	cout << "2-�����ʦ" << endl; 

	string fileName;	//�����ļ���
	string tip;		//��ʾ
	string errorTip;	//�ظ�������ʾ
	ofstream ofs;	//������


/*Bug����:
	���������Ƿ����֣��ͻ������ѭ�����޷������޷�����
*/
	int aSelect = 0;
	cin >> aSelect;
	

	if (aSelect == 1) {
		//�������ļ���ȷ��
		fileName = STUDENT_FILE;
		tip = "������ѧ��:	";
		errorTip = "ѧ���ظ�������������!";
	}
	else if (aSelect == 2) {
		fileName = TEACHER_FILE;
		tip = "�������ְ����: ";
		errorTip = "ְ�����ظ������������룡";
	}
	else {
		cout << "��������!" << endl;
		system("pause");
		system("cls");
		return;
	}

	//����׷�ӷ�ʽд�ļ�
	ofs.open(fileName, ios::out | ios::app);

	int id;
	string name;
	string pwd;

	cout << tip << endl;
	
//����while���������ظ�����,return����break�������
	while (true)
	{
		cin >> id;
		//���id�Ƿ��ظ�(ΨһID)
		bool reapeted = checkRepeat(id, aSelect);

		if (reapeted) {
			cout << errorTip << endl;
		}
		//break����whileѭ�� return�˳����� continue��������ѭ��
		else break;
	}
	

	cout << "����������:" << endl;
	cin >> name;
	cout << "���������룺 " << endl;
	cin >> pwd;

	//���ļ������id���˺š�����
	ofs << id << " " << name << " " << pwd << endl;

	cout << "��ӳɹ���" << endl;
	system("pause");
	system("cls");
	ofs.close();

//��ʱ����һ��BUG�����2�Ų��ظ�����ӳɹ��󣬼������2�ţ���Ȼ������ӣ�������Ϊ������Ϣû�и���
	this->initVector();
}

void Administer::showPerson()
{
	cout << "��ѡ��鿴����:" << endl;
	cout << "1-�鿴������ʦ" << endl;
	cout << "2-�鿴����ѧ��" << endl;

	int asSelect;
	cin>>asSelect;

	if (asSelect == 1) {
		cout << "---------------��ʦ�˺�------------------"<<endl;
		cout << "ְ����" << "\t����" << "\t����" << endl;
		for (vector<Teacher>::iterator it = vTeacher.begin(); it != vTeacher.end(); it++) {
			cout << it->em_Id << "\t" << it->m_Name << "\t" << it->m_Passwod << endl;
		}
	}
	else if (asSelect == 2) {
		cout << "---------------ѧ���˺�------------------"<<endl;
		cout << "ѧ��" << "\t����" << "\t����" << endl;
		for (vector<Student>::iterator sit = vStudent.begin(); sit != vStudent.end(); sit++) {
			cout << sit->m_Id << "\t" << sit->m_Name << "\t" << sit->m_Passwod << endl;
		}
	}
	else {
		cout << "��������!" << endl;
	}
	
	system("pause");
	system("cls");
}

void Administer::showCopRoom()
{
}

void Administer::clearFile()
{
}


