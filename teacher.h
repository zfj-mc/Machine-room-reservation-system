#pragma once
#include<iostream>
#include<vector>
using namespace std;
#include"orderFile.h"
#include"Identity.h"

class Teacher :public Identity
{
public:
	int m_EmpId;
	Teacher();
	Teacher(int Eno, string Name, string Pwd);
	//显示Student子菜单
	virtual void operMenu();
	//查看所有预约   ---   查看全部预约信息以及预约状态
	void showAllOrder();
	//审核预约    ---   对学生的预约进行审核
	void examineOrder();
};

