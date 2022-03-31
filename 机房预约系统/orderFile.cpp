#include "orderFile.h"

orderFile::orderFile()
{
	this->m_Size = 0;

	string date;			//日期
	string interval;		//时间的
	string stuId;		//学生编号
	string stuName;		//学生姓名
	string roomId;			//机房编号
	string status;		//预约状态

	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status) {
		//cout << date << endl;
		//cout << interval << endl;
		map<string, string>m;

		this->insertMap(date, m);
		this->insertMap(interval, m);
		this->insertMap(stuId, m);
		this->insertMap(stuName, m);
		this->insertMap(roomId, m);
		this->insertMap(status, m);

		//插入到OrderFile容器中
		this->mOrderF.insert(make_pair(this->m_Size, m));
		this->m_Size++;

	}

	ifs.close();

	//test 最大的map 是否插入成功
	/*for (map<int, map<string, string>>::iterator it = mOrderF.begin(); it != mOrderF.end(); it++) {
		cout << "key =" << it->first <<" " << "value =" << endl;
		for (map<string, string>::iterator minIt = it->second.begin(); minIt != it->second.end(); minIt++) {
			cout << "key=" << minIt->first <<" " << "value=" << minIt->second << " ";
		}
		cout << endl;
	}	*/
}

void orderFile::updateOrder()
{
	//预约记录0条直接return
	if (this->m_Size == 0) return;	

	//否则更新文件
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	
	for (int i = 0; i < this->m_Size; i++) {
		//写入
		ofs << "date:" << this->mOrderF[i]["date"] << " ";
		ofs << "interval:" << this->mOrderF[i]["interval"] << " ";
		ofs << "stuId:" << this->mOrderF[i]["stuId"] << " ";
		ofs << "stuName:" << this->mOrderF[i]["stuName"] << " ";
		ofs << "roomId:" << this->mOrderF[i]["roomId"] << " ";
		ofs << "status:" << this->mOrderF[i]["date"] << endl;
	}

	ofs.close();
}

void orderFile::insertMap(string &data,map<string,string>&m)
{
	string key;
	string value;

	//date:1234
	int pos = data.find(":");	//pos= 4

	if (pos != -1) {


		//截取
		//data冒号前的部分
		key = data.substr(0, pos);		

		//data冒号后的部分
		value = data.substr(pos + 1, data.size());	//  size=9
			
		//将key-冒号前 value-冒号后插入 map
		m.insert(make_pair(key, value));
	}

}
