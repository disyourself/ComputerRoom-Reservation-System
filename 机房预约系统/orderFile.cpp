#include "orderFile.h"

orderFile::orderFile()
{
	this->m_Size = 0;

	string date;			//����
	string interval;		//ʱ���
	string stuId;		//ѧ�����
	string stuName;		//ѧ������
	string roomId;			//�������
	string status;		//ԤԼ״̬

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

		//���뵽OrderFile������
		this->mOrderF.insert(make_pair(this->m_Size, m));
		this->m_Size++;

	}

	ifs.close();

	//test ����map �Ƿ����ɹ�
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
	//ԤԼ��¼0��ֱ��return
	if (this->m_Size == 0) return;	

	//��������ļ�
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	
	for (int i = 0; i < this->m_Size; i++) {
		//д��
		ofs << "date:" << this->mOrderF[i]["date"] << " ";
		ofs << "interval:" << this->mOrderF[i]["interval"] << " ";
		ofs << "stuId:" << this->mOrderF[i]["stuId"] << " ";
		ofs << "stuName:" << this->mOrderF[i]["stuName"] << " ";
		ofs << "roomId:" << this->mOrderF[i]["roomId"] << " ";
		ofs << "status:" << this->mOrderF[i]["status"] << endl;
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


		//��ȡ
		//datað��ǰ�Ĳ���
		key = data.substr(0, pos);		

		//datað�ź�Ĳ���
		value = data.substr(pos + 1, data.size());	//  size=9
			
		//��key-ð��ǰ value-ð�ź���� map
		m.insert(make_pair(key, value));
	}

}

void orderFile::showAllOrder()
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
			status += "ͨ�����";
		}
		else if (oF.mOrderF[i]["status"] == "-1") {
			status += "���δͨ��";
		}
		else if (oF.mOrderF[i]["status"] == "0") {
			status += "ȡ��ԤԼ";
		}
		cout << status << endl;
	}
}
