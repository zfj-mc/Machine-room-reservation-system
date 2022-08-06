#include<iostream>
#include<fstream>
#include<string>
#include"Identity.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include"globalFile.h"
using namespace std;

//进入教师子菜单
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
			cout << "已退出教师登录" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "输入有误请重新选择" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	
}
//进入学生子菜单
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
			cout << "已退出学生登录" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "输入有误请重新选择" << endl;
			system("pause");
			system("cls");
			break;
		}
		
		

	}
}
//进入管理员的子菜单界面
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//调用管理员子菜单
		manager->operMenu();
		//将父类指针转为子类指针
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
			cout << "已退出管理员登录" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "输入有误请重新选择" << endl;
			system("pause");
			system("cls");
			break;
		}
		

	}
}
//登录功能
void LoginIn(string fileName, int type)//文件名，操作身份
{
	//父类指针用于指向子类对象
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件无法打开" << endl;
		ifs.close();
		system("pause");
		system("cls");
		return;
	}

	//准备接受用户信息
	int id = 0;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入你的职工号：" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入你的密码：" << endl;
	cin >> pwd;
	
	if (type == 1)
	{
		//学生登录验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "身份验证成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入到学生身份的子菜单
				
				studentMenu(person);

				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师登录验证
		int Eno;
		string Sname;
		string Spwd;
		while (ifs >> Eno && ifs >> Sname && ifs >> Spwd)
		{
			if (Eno == id && Sname == name && Spwd == pwd)
			{
				cout << "身份验证成功！" << endl;
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
		//管理员登录验证
		string Sname;
		string Spwd;
		while (ifs >> Sname && ifs >> Spwd)
		{
			if (Sname == name && Spwd == pwd)
			{
				cout << "身份验证成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}
	cout << "身份验证失败！" << endl;
	system("pause");
	system("cls");
	
}
int main()
{
	int select = 0;//接收用户选择
	while (true)
	{
		cout << "===============欢迎来到机房预约系统===============" << endl;
		cout << endl;
		cout << "请输入你的身份" << endl;
		cout << "\t -----------------------\t" << endl;
		cout << "\t|\t1.学生代表\t|\t" << endl;
		cout << "\t|\t\t\t|" << endl;
		cout << "\t|\t2.老    师\t|\t" << endl;
		cout << "\t|\t\t\t|" << endl;
		cout << "\t|\t3.管 理 员\t|\t" << endl;
		cout << "\t|\t\t\t|" << endl;
		cout << "\t|\t0.退    出\t|\t" << endl;
		cout << "\t -----------------------\t" << endl;
		cout << "输入你的选择：" << endl;

		cin >> select;

		switch (select)
		{
		case 1:
			//学生身份
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			//老师身份
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			//管理员身份
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "欢迎下次使用~" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误请重新选择" << endl;
			system("pause");
			system("cls");
			break;
		}
		
	}
	system("pause");
	return 0;
}