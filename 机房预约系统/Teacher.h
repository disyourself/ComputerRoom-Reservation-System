#pragma once
#include "Identity.h"
#include "orderFile.h"
class Teacher :public Identity
{
public:
	Teacher();

	Teacher(int emId, string name, string pwd);

	// �˵�����
	virtual void openMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void reviewOrder();

private:

	//��ʦ�˵�
	void teacherMenu();


public:

	int em_Id;
};

