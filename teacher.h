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
	//��ʾStudent�Ӳ˵�
	virtual void operMenu();
	//�鿴����ԤԼ   ---   �鿴ȫ��ԤԼ��Ϣ�Լ�ԤԼ״̬
	void showAllOrder();
	//���ԤԼ    ---   ��ѧ����ԤԼ�������
	void examineOrder();
};

