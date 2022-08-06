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
	//��ʾStudent�Ӳ˵�
	virtual void operMenu();
	//����˺�    ---   ���ѧ�����ʦ���˺ţ���Ҫ���ѧ����Ż��ʦְ�����Ƿ��ظ�
	void addPerson();
	//�鿴�˺�    ---   ����ѡ��鿴ѧ�����ʦ��ȫ����Ϣ
	void showPerson();
	//�鿴����    ---   �鿴���л�������Ϣ
	void showComputer();
	//���ԤԼ    ---   �������ԤԼ��¼
	void clearOrder();

	//��ʼ������
	void initVector();
	//ѧ������
	vector<Student> vStu;
	//��ʦ����
	vector<Teacher> vTea;

	//����ظ�
	bool checkRepeat(int id, int type);


	//void getvComputer();
	vector<ComputerRoom>vCom;

};
