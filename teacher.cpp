#include"teacher.h"

Teacher::Teacher()
{

}
Teacher::Teacher(int empId, string name, string pwd)
{
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}
//��ʾStudent�Ӳ˵�
void Teacher::operMenu()
{
	cout << "��ӭ��ʦ��¼" << endl;
	cout << "\t -------------------------------\t" << endl;
	cout << "\t|\t1.�鿴����ԤԼ\t\t|\t" << endl;
	cout << "\t|\t\t\t\t|" << endl;
	cout << "\t|\t2.�� ��  Ԥ Լ\t\t|\t" << endl;
	cout << "\t|\t\t\t\t|" << endl;
	cout << "\t|\t0.�� ��  �� ¼\t\t|\t" << endl;
	cout << "\t -------------------------------\t" << endl;
	cout << "������ѡ��Ĳ�����";
}
//�鿴����ԤԼ   ---   �鿴ȫ��ԤԼ��Ϣ�Լ�ԤԼ״̬
void Teacher::showAllOrder()
{
	OrderFile of;
	//ifstream ifs;
	//ifs.open(ORDER_FILE,ios::in);
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
//���ԤԼ    ---   ��ѧ����ԤԼ�������
void Teacher::examineOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
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

	cout << "��ѡ������ĸ�ԤԼ�������,0������" << endl;
	int sel;
	while (true)
	{
		cin >> sel;
		if (sel >= 0 && sel <= v.size())
		{
			if (sel == 0)
			{
				break;
			}
			else
			{
				//	cout << "��¼����λ�ã� " << v[select - 1] << endl;
				int ch;
				cout << "1.ͨ��ԤԼ" << endl;
				cout << "2.ȡ�������ԤԼ" << endl;
				cin >> ch;
				if (ch == 1 || ch == 2)
				{
					if (ch == 1)
					{
						of.m_orderData[v[sel - 1]]["status"] = "2";
						of.updateOrder();
						cout << "ͨ���ɹ�" << endl;
						break;
					}
					else if (ch == 2)
					{
						of.m_orderData[v[sel - 1]]["status"] = "-1";
						of.updateOrder();
						cout << "��ȡ��ԤԼ" << endl;
						break;
					}
				}
				cout << "������������������" << endl;
			}
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");

}