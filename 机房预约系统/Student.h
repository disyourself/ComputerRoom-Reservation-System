#pragma once
#include "Identity.h"
#include"computerRoom.h"
#include"orderFile.h"

class Student :public Identity
{
public:
	//Ĭ�Ϲ���
	Student();

	//�вι���
	Student(int id, string name, string pwd);

	//�˵�����
	void openMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void checkMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

private:

	//ѧ������
	void studentMenu();

public:

	int m_Id;

	vector<computerRoom>vCopRoom;	//��������

};

