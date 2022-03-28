#pragma once
#include "Identity.h"
#include"Student.h"
#include"Teacher.h"

class Administer :public Identity
{
public:
    Administer();

    Administer(string name, string pwd);

    //�������Ա�˵�
    virtual void openMenu();

    //����˺�
    void addAccount();

    //�鿴�˺�
    void showPerson();

    //�鿴����
    void showCopRoom();

    //���ԤԼ
    void clearFile();

private:
    //�˵�����
    void adminMenu();

    //��ʼ������
    void initVector();

    //�����ʦ��ѧ��id�Ƿ��ظ�
    bool checkRepeat(int id, int type);

    vector<Teacher>vTeacher;    //��ʦ����
    vector<Student>vStudent;       //ѧ������

};

