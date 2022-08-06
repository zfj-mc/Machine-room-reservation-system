#pragma once
#include<iostream>
using namespace std;
#include"globalFile.h"

#include<map>
#include<string>
#include<fstream>

class OrderFile
{
public:
	OrderFile();
	//更新预约记录
	void updateOrder();

	int m_Size;//记录预约条数

	map<int, map<string, string>> m_orderData;
};