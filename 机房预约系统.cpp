#include<iostream>
#include<fstream>
#include<string>
#include"Identity.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include"globalFile.h"
using namespace std;

//�����ʦ�Ӳ˵�
void teacherMenu(Identity*& teacher)
{
	Teacher* tea = (Teacher*)teacher;
	while (true)
	{
		tea->operMenu();
		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			tea->showAllOrder();
			break;
		case 2:
			tea->examineOrder();
			break;
		case 0:
			delete teacher;
			cout << "���˳���ʦ��¼" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	
}
//����ѧ���Ӳ˵�
void studentMenu(Identity*& student)
{
	Student* stu = (Student*)student;

	while (true)
	{
		stu->operMenu();
		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			stu->applyOrder();
			break;
		case 2:
			stu->showMyOrder();
			break;
		case 3:
			stu->showAllOrder();
			break;
		case 4:
			stu->cancelOrder();
			break;
		case 0:
			delete student;
			cout << "���˳�ѧ����¼" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
		
		

	}
}
//�������Ա���Ӳ˵�����
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		manager->operMenu();
		//������ָ��תΪ����ָ��
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1:
			man->addPerson();
			break;
		case 2:
			man->showPerson();
			break;
		case 3:
			man->showComputer();
			break;
		case 4:
			man->clearOrder();
			break;
		case 0:
			delete manager;
			cout << "���˳�����Ա��¼" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
		

	}
}
//��¼����
void LoginIn(string fileName, int type)//�ļ������������
{
	//����ָ������ָ���������
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ��޷���" << endl;
		ifs.close();
		system("pause");
		system("cls");
		return;
	}

	//׼�������û���Ϣ
	int id = 0;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "���������ְ���ţ�" << endl;
		cin >> id;
	}
	cout << "�������û�����" << endl;
	cin >> name;
	cout << "������������룺" << endl;
	cin >> pwd;
	
	if (type == 1)
	{
		//ѧ����¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "�����֤�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//���뵽ѧ����ݵ��Ӳ˵�
				
				studentMenu(person);

				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ��¼��֤
		int Eno;
		string Sname;
		string Spwd;
		while (ifs >> Eno && ifs >> Sname && ifs >> Spwd)
		{
			if (Eno == id && Sname == name && Spwd == pwd)
			{
				cout << "�����֤�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա��¼��֤
		string Sname;
		string Spwd;
		while (ifs >> Sname && ifs >> Spwd)
		{
			if (Sname == name && Spwd == pwd)
			{
				cout << "�����֤�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}
	cout << "�����֤ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	
}
int main()
{
	int select = 0;//�����û�ѡ��
	while (true)
	{
		cout << "===============��ӭ��������ԤԼϵͳ===============" << endl;
		cout << endl;
		cout << "������������" << endl;
		cout << "\t -----------------------\t" << endl;
		cout << "\t|\t1.ѧ������\t|\t" << endl;
		cout << "\t|\t\t\t|" << endl;
		cout << "\t|\t2.��    ʦ\t|\t" << endl;
		cout << "\t|\t\t\t|" << endl;
		cout << "\t|\t3.�� �� Ա\t|\t" << endl;
		cout << "\t|\t\t\t|" << endl;
		cout << "\t|\t0.��    ��\t|\t" << endl;
		cout << "\t -----------------------\t" << endl;
		cout << "�������ѡ��" << endl;

		cin >> select;

		switch (select)
		{
		case 1:
			//ѧ�����
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			//��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			//����Ա���
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��~" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
		
	}
	system("pause");
	return 0;
}