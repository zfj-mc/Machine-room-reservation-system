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

	//��ʾStudent�Ӳ˵�
	virtual void operMenu();
	// ����ԤԼ --- ԤԼ����
	void applyOrder();
	// �鿴�����ԤԼ --- �鿴�Լ���ԤԼ״̬
	void showMyOrder();
	// �鿴����ԤԼ --- �鿴ȫ��ԤԼ��Ϣ�Լ�ԤԼ״̬
	void showAllOrder();
	// ȡ��ԤԼ --- ȡ�������ԤԼ��ԤԼ�ɹ�������е�ԤԼ����ȡ��
	void cancelOrder();
	//ѧ��ѧ��
	int m_Id;
	vector<ComputerRoom>vCom;
	
};