#pragma once
#include "Identity.h"
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


	int em_Id;
};

