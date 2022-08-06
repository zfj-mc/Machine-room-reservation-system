#include"student.h"


Student::Student()
{

}
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	ifstream ifs;
	ifs.open(COMPUTERROOM_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
}

//��ʾStudent�Ӳ˵�
void Student::operMenu()
{
	cout << "��ӭͬѧ��¼" << endl;
	cout << "\t -------------------------------\t" << endl;
	cout << "\t|\t1.�� ��  Ԥ Լ\t\t|\t" << endl;
	cout << "\t|\t\t\t\t|" << endl;
	cout << "\t|\t2.�鿴����ԤԼ\t\t|\t" << endl;
	cout << "\t|\t\t\t\t|" << endl;
	cout << "\t|\t3.�鿴����ԤԼ\t\t|\t" << endl;
	cout << "\t|\t\t\t\t|" << endl;
	cout << "\t|\t4.ȡ ��  Ԥ Լ\t\t|\t" << endl;
	cout << "\t|\t\t\t\t|" << endl;
	cout << "\t|\t0.�� ��  �� ¼\t\t|\t" << endl;
	cout << "\t -------------------------------\t" << endl;
	cout << "������ѡ��Ĳ�����" << endl;

}
// ����ԤԼ --- ԤԼ����
void Student::applyOrder()
{
	cout << "�����ɹ�ԤԼ��ʱ���Ϊ��һ�����壬��ѡ������ҪԤԼ��ʱ�䣺" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;

	int date = 0;//����
	int interval = 0;//ʱ���
	int room = 0;
	while (true)
	{
		cin >> date;
		if (date >= 1 || date <= 5)
		{
			break;
		}
		else
		{
			cout << "��淶���룺" << endl;;
		}
	}
	cout << "��ѡ����ҪԤԼ��ʱ��Σ�" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	while (true)
	{
		cin >> interval;
		if (interval == 1 || interval == 2)
		{
			break;
		}
		else
		{
			cout << "��淶���룺" << endl;;
		}
	}
	cout << "��ѡ����ҪԤԼ�Ļ�����" << endl;
	cout << "1.һ�Ż��� ������20" << endl;
	cout << "2.һ�Ż��� ������50" << endl;
	cout << "3.һ�Ż��� ������100" << endl;
	while (true)
	{
		cin >> room;
		if (room == 1 || room == 2 || room == 3)
		{
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "ԤԼ�ɹ��������" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close();
	system("pause");
	system("cls");
	
}
// �鿴�����ԤԼ --- �鿴�Լ���ԤԼ״̬
void Student::showMyOrder()
{
	OrderFile of;
	//ifstream ifs;
	//ifs.open(ORDER_FILE, ios::in);
	if (of.m_Size == 0)
	{
		cout << "���ڻ�û��ԤԼ��Ϣ" << endl;
		system("pause");
		system("cls");
		return;
	}
	int j = 1;

	for (map<int, map<string, string>>::iterator it = of.m_orderData.begin(); it != of.m_orderData.end(); it++)
	{
		int i = 1;

		for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
		{

			if (mit->second == to_string(this->m_Id))
			{
				cout << j << "��";
				for (map<string, string>::iterator Mit = it->second.begin(); Mit != it->second.end(); Mit++)
				{
					if (i == 1)
					{
						cout << "����";
						cout << Mit->second << " ";
					}
					else if (i == 2)
					{
						cout << "ʱ�Σ�" << "";
						cout << ((Mit->second) == "1" ? "����" : "����") << " ";
					}
					else if (i == 3)
					{
						cout << "������";
						cout << Mit->second << " ";
					}

					else if (i == 4)
					{
						cout << "״̬��";
						if (Mit->second == "1")
						{
							cout << "�����" << endl;
						}
						else if (Mit->second == "2")
						{
							cout << "ԤԼ�ɹ�" << endl;
						}
						else if (Mit->second == "-1")
						{
							cout << "ԤԼʧ��" << endl;
						}
						else
						{
							cout << "��ȡ��" << endl;
						}
					}

					i++;
				}
				j++;
			}

		}
	}

	//ifs.close();
	system("pause");
	system("cls");
}
	
// �鿴����ԤԼ --- �鿴ȫ��ԤԼ��Ϣ�Լ�ԤԼ״̬
void Student::showAllOrder()
{
	OrderFile of;

	if (of.m_Size == 0)
	{
		cout << "���ڻ�û��ԤԼ��Ϣ" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (map<int, map<string, string>>::iterator it = of.m_orderData.begin(); it != of.m_orderData.end(); it++)
	{
		cout << it->first + 1 << "��";
		int i = 1;
		for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
		{
			if (i == 1)
			{
				cout << "����";
				cout << mit->second << " ";
			}
			else if (i == 2)
			{
				cout << "ʱ�Σ�" << "";
				cout << ((mit->second) == "1" ? "����" : "����") << " ";
			}
			else if (i == 3)
			{
				cout << "������";
				cout << mit->second << " ";
			}
			else if (i == 4)
			{
				cout << "״̬��";
				if (mit->second == "1")
				{
					cout << "�����" << " ";
				}
				else if (mit->second == "2")
				{
					cout << "ԤԼ�ɹ�" << " ";
				}
				else if (mit->second == "-1")
				{
					cout << "ԤԼʧ��" << " ";
				}
				else
				{
					cout << "��ȡ��" << " ";
				}
			}
			else if (i == 5)
			{
				cout << "ѧ�ţ�";
				cout << mit->second << " ";
			}
			else if (i == 6)
			{
				cout << "������";
				cout << mit->second << " " << endl;
			}
			i++;
		}
	}


	//ifs.close();
	system("pause");
	system("cls");
}
// ȡ��ԤԼ --- ȡ�������ԤԼ��ԤԼ�ɹ�������е�ԤԼ����ȡ��
void Student::cancelOrder()
{
	
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;

	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)
		{
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "�� ";
				cout << "ԤԼ���ڣ� ��" << of.m_orderData[i]["date"];
				cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
				cout << " ������" << of.m_orderData[i]["roomId"];
				string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ  -1 ԤԼʧ��
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;

			}
		}
	}

	cout << "������ȡ���ļ�¼,0������" << endl;
	cout << v.size() << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				//	cout << "��¼����λ�ã� " << v[select - 1] << endl;
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}

		}
		cout << "������������������" << endl;
	}

	system("pause");
	system("cls");
	

}