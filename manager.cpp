#include"manager.h"

Manager::Manager()
{

}
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initVector();

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTERROOM_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
}
//显示子菜单
void Manager::operMenu()
{
	cout << "欢迎管理员:" << this->m_Name << "登录" << endl;
	cout << "\t -------------------------------\t" << endl;
	cout << "\t|\t1.添 加  账 号\t\t|\t" << endl;
	cout << "\t|\t\t\t\t|" << endl;
	cout << "\t|\t2.查 看  账 号\t\t|\t" << endl;
	cout << "\t|\t\t\t\t|" << endl;
	cout << "\t|\t3.查 看  机 房\t\t|\t" << endl;
	cout << "\t|\t\t\t\t|" << endl;
	cout << "\t|\t4.清 空  预 约\t\t|\t" << endl;
	cout << "\t|\t\t\t\t|" << endl;
	cout << "\t|\t0.退 出  登 录\t\t|\t" << endl;
	cout << "\t -------------------------------\t" << endl;
	cout << "输入你选择的操作：" << endl;
	
}
//添加账号    ---   添加学生或教师的账号，需要检测学生编号或教师职工号是否重复
void Manager::addPerson()
{
	int select = 0;

	string fileName;//操作文件名
	string tip;//提示id号
	string errorTip;//错误提示

	cout << "请输入你想添加的用户类型：" << endl;
	cout << "1.学生" << endl;
	cout << "2.老师" << endl;

	ofstream ofs;
	cin >> select;

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "学号重复，请重新输入：";

	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
		errorTip = "职工号重复，请重新输入：";
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
	
	
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	//向文件中写入
	ofs << id << " " << name << " " << pwd << "" << endl;
	cout << " 添加成功" << endl;
	system("pause");
	system("cls");

	ofs.close();

	//调用初始化容器的接口
	this->initVector();
}


void printStduent(Student& s)
{
	cout << "学号：" << s.m_Id << "\t姓名：" << s.m_Name << "\t密码：" << s.m_Pwd << endl;
}
void printTeacher(Teacher &t)
{
	cout << "学号：" << t.m_EmpId << "\t姓名：" << t.m_Name << "\t密码：" << t.m_Pwd << endl;
}

//查看账号    ---   可以选择查看学生或教师的全部信息
void Manager::showPerson()
{
	cout << "请输入你要查看账号的类型：" << endl;
	cout << "1.学生" << endl;
	cout << "2.老师" << endl;
	//cout << "3.管理员" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		cout << "所有学生信息如下：" << endl;
		for_each(vStu.begin(), vStu.end(), printStduent);

	}
	else
	{
		
		for_each(vTea.begin(), vTea.end(), printTeacher);
		
	}
	system("pause");
	system("cls");
	
}
//查看机房    ---   查看所有机房的信息
void Manager::showComputer()
{
	cout << "机房信息如下：" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号：" << it->m_ComId << "\t电脑数量：" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}
//清空预约    ---   清空所有预约记录
void Manager::clearOrder()
{
	cout << "请再次确认，清空后不可恢复！" << endl;
	cout << "输入1-------确认" << endl;
	cout << "输入其他----取消" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		ofstream ofs;
		ofs.open(ORDER_FILE, ios::trunc);
		ofs.close();

		cout << "清空成功！" << endl;
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
//初始化容器
void Manager::initVector()
{
	vStu.clear();
	vTea.clear();
	//读取信息

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
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
		cout << "文件读取失败" << endl;
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
//检测重复
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//检测学生
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