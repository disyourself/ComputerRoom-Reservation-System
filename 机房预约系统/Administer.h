#pragma once
#include "Identity.h"
#include"Student.h"
#include"Teacher.h"

class Administer :public Identity
{
public:
    Administer();

    Administer(string name, string pwd);

    //进入管理员菜单
    virtual void openMenu();

    //添加账号
    void addAccount();

    //查看账号
    void showPerson();

    //查看机房
    void showCopRoom();

    //清空预约
    void clearFile();

private:
    //菜单界面
    void adminMenu();

    //初始化容器
    void initVector();

    //检测老师或学生id是否重复
    bool checkRepeat(int id, int type);

    vector<Teacher>vTeacher;    //老师容器
    vector<Student>vStudent;       //学生容器

};

