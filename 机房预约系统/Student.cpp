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

	//初始化机房信息
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
		case 1:		//申请预约
			cout << "申请预约:" << endl;
			this->applyOrder();
			break;
		case 2:		//查看自身预约
			cout << "查看自身预约:" << endl;
			this->checkMyOrder();
			break;
		case 3:		//查看所有预约
			cout << "查看所有预约:" << endl;
			this->showAllOrder();
			break;
		case 4:		//取消预约
			cout << "取消预约:" << endl;
			this->cancelOrder();
			break;
		case 0:		//注销退出
			delete this;
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

void Student::applyOrder()
{
	cout << "机房开放时间为周一至周五" << endl;
	cout << "--请输入你要预约的时间:" << endl;
	cout << "1|2|3|4|5(周一至周五)" << endl;

	int aoDay = 0;		//日期
	int interval = 0;	//时间段
	int room = 0;		//机房编号
	
	while (true) {
		cin >> aoDay;
		if (aoDay >= 1 && aoDay <= 5) break;
		cout << "输入有误,请重新输入" << endl;
	}

	cout << "请输入申请预约的时间:" << endl;
	cout << "1-上午" << endl << "2-下午" << endl;

	while (true)
	{
		cin >> interval;
		if (interval == 1 || interval == 2) break;
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "请输入预约的机房号:" << endl;
	cout << "1~3" << endl;

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3) break;
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "预约成功！审核中" << endl;


	system("pause");
	system("cls");

	ofstream ofs;
	
	//文件写入预约信息
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
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < oF.m_Size; i++) {
		//string 转为 int
		//if (stoi(oF.mOrderF[i]["stuId"]) == this->m_Id) {
		if(atoi(oF.mOrderF[i]["stuId"].c_str())==this->m_Id){
			//找到了自身的预约
			cout << "预约日期: 周" << oF.mOrderF[i]["date"];
			cout << " 时间段: " << (oF.mOrderF[i]["date"]=="1"?"上午":"下午");
			cout << " 机房号: " << oF.mOrderF[i]["roomId"];
			string status = " 状态: ";
			//1-盛和中 2 已预约 -1 预约失败 0 取消预约
			if (oF.mOrderF[i]["status"] == "1") {
				status += "审核中";
			}
			else if (oF.mOrderF[i]["status"] == "2") {
				status += "预约成功";
			}
			else if (oF.mOrderF[i]["status"] == "-1") {
				status += "预约失败,审核未通过";
			}
			else if (oF.mOrderF[i]["status"] == "0") {
				status += "取消预约";
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
		cout << "预约记录为空" << endl;
		return;
	}

	for (int i = 0; i < oF.m_Size; i++) {
		cout << "预约日期: 周" << oF.mOrderF[i]["date"];
		cout << " 时间段: " << (oF.mOrderF[i]["date"] == "1" ? "上午" : "下午");
		cout << " 机房号: " << oF.mOrderF[i]["roomId"];

		cout << " 学号: " << oF.mOrderF[i]["stuId"];
		cout << " 姓名： " << oF.mOrderF[i]["stuName"];


		string status = " 状态: ";
		//1-盛和中 2 已预约 -1 预约失败 0 取消预约
		if (oF.mOrderF[i]["status"] == "1") {
			status += "审核中";
		}
		else if (oF.mOrderF[i]["status"] == "2") {
			status += "预约成功";
		}
		else if (oF.mOrderF[i]["status"] == "-1") {
			status += "预约失败,审核未通过";
		}
		else if (oF.mOrderF[i]["status"] == "0") {
			status += "取消预约";
		}
		cout << status << endl;
	}
}

void Student::cancelOrder()
{
	orderFile oF;
	if (oF.m_Size == 0) {
		cout << "预约记录为空" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "审核中或预约成功的记录可以取消,请输入取消的记录:" << endl;
	cout << "___________________________________" << endl;

	vector<int>v;		//存放在最大容器中的下标编号;
	int index = 1;
	for (int i = 0; i < oF.m_Size; i++) {
		if (atoi(oF.mOrderF[i]["stuId"].c_str()) == this->m_Id) {
			//筛选状态 审核中或预约成功
			if (oF.mOrderF[i]["status"] == "1" || oF.mOrderF[i]["status"] == "2") {


				//向vector插入大map的key值
				v.push_back(i);


				cout << index++ << " ";
				cout << "预约日期: " << oF.mOrderF[i]["date"];
				cout << "时间段: " << (oF.mOrderF[i]["interval"] == "1"? "上午":"下午");
				cout << "机房号: " << oF.mOrderF[i]["roomId"];
				
				string status = " 状态: ";
				if (oF.mOrderF[i]["status"] == "1") {
					status += "审核中";
				}
				else if (oF.mOrderF[i]["status"] == "2") {
					status += "预约成功";
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
				//0 退出删除操作
				break;
			else {
				//v[ccSelect-1]
				oF.mOrderF[v[ccSelect - 1]]["satus"] = "0";

				cout << "取消预约成功！" << endl;
				//重写orderFile文件
				//写入修改后的信息
				oF.updateOrder();
				break;
			}
		}
		
		cout << "输入有误,请重新输入";
	}

	system("pause");
	system("cls");
}

void Student::studentMenu()
{
	cout << "欢迎" << this->m_Name << "同学登录系统" << endl;
	cout << "-----------------------------" << endl;
	cout << "请选择你的操作：" << endl;
	cout << "  1-申请预约" << endl;
	cout << "  2-查看自身预约" << endl;
	cout << "  3-查看所有预约" << endl;
	cout << "  4-取消预约" << endl;
	cout << "  0-注销登录" << endl;
	cout << "------------------------------" << endl;
}
