#include "Administer.h"
#include<fstream>

Administer::Administer()
{
	this->initVector();
}

//有参构造
Administer::Administer(string name, string pwd)
{
	//初始化管理员信息
	this->m_Name = name;
	this->m_Passwod = pwd;
	
	//初始化容器，获取所有文件中的老师、学生
	this->initVector();
}


//形参跟实参都是n级(1级）指针的时候，形参不会指向实参，而是对实参的拷贝，如果想让（引用的）形参指向实参，需要升一级（加*号）
//后面用->代替.调用里面的函数 Identity *&perosn
//但是用this 传入好像不用
void Administer::openMenu()
{
	while (true) {
		//调用管理员子菜单
		this->adminMenu();

		//将父类指针转为子类指针，调用子类里的其他接口
		Administer* admin = (Administer*)this;

		int _select;
		cin >> _select;

		switch (_select)
		{
		case 1:		//添加账号
			cout << "添加账号:" << endl;
			admin->addAccount();
			break;
		case 2:		//查看账号
			cout << "查看账号:" << endl;
			admin->showPerson();
			break;
		case 3:		//查看机房
			cout << "查看机房:" << endl;
			admin->showCopRoom();
			break;
		case 4:		//清空预约
			cout << "清空预约:" << endl;
			admin->clearFile();
			break;
		case 0:		//注销退出
			delete admin;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "无效输入!请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}


void Administer::adminMenu()
{
	cout << "-----------------------------" << endl;
	cout << "欢迎管理员" << this->m_Name << "登录!" << endl;
	cout << "  1-添加账号" << endl;
	cout << "  2-查看账号" << endl;
	cout << "  3-查看机房" << endl;
	cout << "  4-清空预约" << endl;
	cout << "  0-退出系统" << endl;
	cout << "------------------------------" << endl;
	cout << "请选择您的操作: " << endl;

}

void Administer::initVector()
{
	vStudent.clear();
	vTeacher.clear();

	ifstream ifs;

//读取信息 学生
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << STUDENT_FILE << "文件读取失败!" << endl;
		return;
	}

	Student s;
	//读到空格会停止 读下一个
	while (ifs>>s.m_Id&&ifs>>s.m_Name&&ifs>>s.m_Passwod){
		vStudent.push_back(s);
	}

	cout << "当前的学生数量为:" << vStudent.size() << endl;
	ifs.close();

//读取信息 老师
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << TEACHER_FILE << "文件读取失败!" << endl;
		return;
	}

	Teacher t;
	//读到空格会停止 读下一个
	while (ifs >> t.em_Id && ifs >> t.m_Name && ifs >> t.m_Passwod) {
		vTeacher.push_back(t);
	}

	cout << "当前的老师数量为:" << vStudent.size() << endl;
	ifs.close();

}

bool Administer::checkRepeat(int id, int type)
{
	if (type == 1) {
		//检测学生
		for (vector<Student>::iterator it = vStudent.begin(); it != vStudent.end(); it++) {
			if (it->m_Id == id) return true;
		}
	}
	else{
		//检测老师
		for (vector<Teacher>::iterator it=vTeacher.begin(); it!=vTeacher.end(); it++){
			if (it->em_Id == id)return true;
		}
	}
	
	return false;
}



void Administer::addAccount()
{
	cout << "请输入添加账号的类型:" << endl;
	cout << "1-添加学生" << endl;
	cout << "2-添加老师" << endl; 

	string fileName;	//操作文件名
	string tip;		//提示
	string errorTip;	//重复错误提示
	ofstream ofs;	//流对象


/*Bug发现:
	如果输入的是非数字，就会进入死循环，无法输入无法操作
*/
	int aSelect = 0;
	cin >> aSelect;
	

	if (aSelect == 1) {
		//将操作文件名确定
		fileName = STUDENT_FILE;
		tip = "请输入学号:	";
		errorTip = "学号重复，请重新输入!";
	}
	else if (aSelect == 2) {
		fileName = TEACHER_FILE;
		tip = "请输入教职工号: ";
		errorTip = "职工号重复，请重新输入！";
	}
	else {
		cout << "输入有误!" << endl;
		system("pause");
		system("cls");
		return;
	}

	//利用追加方式写文件
	ofs.open(fileName, ios::out | ios::app);

	int id;
	string name;
	string pwd;

	cout << tip << endl;
	
//放在while里来避免重复输入,return或者break重新输出
	while (true)
	{
		cin >> id;
		//检测id是否重复(唯一ID)
		bool reapeted = checkRepeat(id, aSelect);

		if (reapeted) {
			cout << errorTip << endl;
		}
		//break跳出while循环 return退出函数 continue跳过本轮循环
		else break;
	}
	

	cout << "请输入姓名:" << endl;
	cin >> name;
	cout << "请输入密码： " << endl;
	cin >> pwd;

	//向文件中添加id、账号、密码
	ofs << id << " " << name << " " << pwd << endl;

	cout << "添加成功！" << endl;
	system("pause");
	system("cls");
	ofs.close();

//此时存在一个BUG，如果2号不重复，添加成功后，继续添加2号，仍然可以添加，这是因为容器信息没有更新
	this->initVector();
}

void Administer::showPerson()
{
	cout << "请选择查看内容:" << endl;
	cout << "1-查看所有老师" << endl;
	cout << "2-查看所有学生" << endl;

	int asSelect;
	cin>>asSelect;

	if (asSelect == 1) {
		cout << "---------------老师账号------------------"<<endl;
		cout << "职工号" << "\t姓名" << "\t密码" << endl;
		for (vector<Teacher>::iterator it = vTeacher.begin(); it != vTeacher.end(); it++) {
			cout << it->em_Id << "\t" << it->m_Name << "\t" << it->m_Passwod << endl;
		}
	}
	else if (asSelect == 2) {
		cout << "---------------学生账号------------------"<<endl;
		cout << "学号" << "\t姓名" << "\t密码" << endl;
		for (vector<Student>::iterator sit = vStudent.begin(); sit != vStudent.end(); sit++) {
			cout << sit->m_Id << "\t" << sit->m_Name << "\t" << sit->m_Passwod << endl;
		}
	}
	else {
		cout << "操作错误!" << endl;
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


