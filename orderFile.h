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
	//����ԤԼ��¼
	void updateOrder();

	int m_Size;//��¼ԤԼ����

	map<int, map<string, string>> m_orderData;
};