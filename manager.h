#pragma once
#include"student.h"
#include <iostream>
#include "identity.h"
#include <string>
#include <fstream>
#include<algorithm>
#include "globalFile.h"
#include"teacher.h"
#include "computerRoom.h"
#include <vector>

using namespace std;

class Manager :public Identity
{
public:
	Manager();
	Manager(string name, string pwd);
	//显示Student子菜单
	virtual void operMenu();
	//添加账号    ---   添加学生或教师的账号，需要检测学生编号或教师职工号是否重复
	void addPerson();
	//查看账号    ---   可以选择查看学生或教师的全部信息
	void showPerson();
	//查看机房    ---   查看所有机房的信息
	void showComputer();
	//清空预约    ---   清空所有预约记录
	void clearOrder();

	//初始化容器
	void initVector();
	//学生容器
	vector<Student> vStu;
	//教师容器
	vector<Teacher> vTea;

	//检测重复
	bool checkRepeat(int id, int type);


	//void getvComputer();
	vector<ComputerRoom>vCom;

};
