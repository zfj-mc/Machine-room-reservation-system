#pragma once
#include"Identity.h"
#include"globalFile.h"
#include"computerRoom.h"
#include"orderFile.h"
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include<iostream>
using namespace std;
class Student :public Identity
{
public:
	Student();
	Student(int id, string name, string pwd);

	//显示Student子菜单
	virtual void operMenu();
	// 申请预约 --- 预约机房
	void applyOrder();
	// 查看自身的预约 --- 查看自己的预约状态
	void showMyOrder();
	// 查看所有预约 --- 查看全部预约信息以及预约状态
	void showAllOrder();
	// 取消预约 --- 取消自身的预约，预约成功或审核中的预约均可取消
	void cancelOrder();
	//学生学号
	int m_Id;
	vector<ComputerRoom>vCom;
	
};