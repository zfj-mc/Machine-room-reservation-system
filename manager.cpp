#include"manager.h"

Manager::Manager()
{

}
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initVector();

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTERROOM_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
}
//��ʾ�Ӳ˵�
void Manager::operMenu()
{
	cout << "��ӭ����Ա:" << this->m_Name << "��¼" << endl;
	cout << "\t -------------------------------\t" << endl;
	cout << "\t|\t1.�� ��  �� ��\t\t|\t" << endl;
	cout << "\t|\t\t\t\t|" << endl;
	cout << "\t|\t2.�� ��  �� ��\t\t|\t" << endl;
	cout << "\t|\t\t\t\t|" << endl;
	cout << "\t|\t3.�� ��  �� ��\t\t|\t" << endl;
	cout << "\t|\t\t\t\t|" << endl;
	cout << "\t|\t4.�� ��  Ԥ Լ\t\t|\t" << endl;
	cout << "\t|\t\t\t\t|" << endl;
	cout << "\t|\t0.�� ��  �� ¼\t\t|\t" << endl;
	cout << "\t -------------------------------\t" << endl;
	cout << "������ѡ��Ĳ�����" << endl;
	
}
//����˺�    ---   ���ѧ�����ʦ���˺ţ���Ҫ���ѧ����Ż��ʦְ�����Ƿ��ظ�
void Manager::addPerson()
{
	int select = 0;

	string fileName;//�����ļ���
	string tip;//��ʾid��
	string errorTip;//������ʾ

	cout << "������������ӵ��û����ͣ�" << endl;
	cout << "1.ѧ��" << endl;
	cout << "2.��ʦ" << endl;

	ofstream ofs;
	cin >> select;

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ������������룺";

	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errorTip = "ְ�����ظ������������룺";
	}
	ofs.open(fileName, ios::out | ios::app);

	int id;
	string name;
	string pwd;
	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}
	
	
	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	//���ļ���д��
	ofs << id << " " << name << " " << pwd << "" << endl;
	cout << " ��ӳɹ�" << endl;
	system("pause");
	system("cls");

	ofs.close();

	//���ó�ʼ�������Ľӿ�
	this->initVector();
}


void printStduent(Student& s)
{
	cout << "ѧ�ţ�" << s.m_Id << "\t������" << s.m_Name << "\t���룺" << s.m_Pwd << endl;
}
void printTeacher(Teacher &t)
{
	cout << "ѧ�ţ�" << t.m_EmpId << "\t������" << t.m_Name << "\t���룺" << t.m_Pwd << endl;
}

//�鿴�˺�    ---   ����ѡ��鿴ѧ�����ʦ��ȫ����Ϣ
void Manager::showPerson()
{
	cout << "��������Ҫ�鿴�˺ŵ����ͣ�" << endl;
	cout << "1.ѧ��" << endl;
	cout << "2.��ʦ" << endl;
	//cout << "3.����Ա" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), printStduent);

	}
	else
	{
		
		for_each(vTea.begin(), vTea.end(), printTeacher);
		
	}
	system("pause");
	system("cls");
	
}
//�鿴����    ---   �鿴���л�������Ϣ
void Manager::showComputer()
{
	cout << "������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "������ţ�" << it->m_ComId << "\t����������" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}
//���ԤԼ    ---   �������ԤԼ��¼
void Manager::clearOrder()
{
	cout << "���ٴ�ȷ�ϣ���պ󲻿ɻָ���" << endl;
	cout << "����1-------ȷ��" << endl;
	cout << "��������----ȡ��" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		ofstream ofs;
		ofs.open(ORDER_FILE, ios::trunc);
		ofs.close();

		cout << "��ճɹ���" << endl;
	}
	else if (choice != 1)
	{
		system("pause");
		system("cls");
		return;
	}
	system("pause");
	system("cls");
	
}
//��ʼ������
void Manager::initVector()
{
	vStu.clear();
	vTea.clear();
	//��ȡ��Ϣ

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		//ifs.close();
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	//cout << vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		//ifs.close();
		return;
	}

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	//cout << vTea.size() << endl;
	ifs.close();

}
//����ظ�
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//���ѧ��
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}

	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}