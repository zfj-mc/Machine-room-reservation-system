#include"teacher.h"

Teacher::Teacher()
{

}
Teacher::Teacher(int empId, string name, string pwd)
{
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}
//显示Student子菜单
void Teacher::operMenu()
{
	cout << "欢迎老师登录" << endl;
	cout << "\t -------------------------------\t" << endl;
	cout << "\t|\t1.查看所有预约\t\t|\t" << endl;
	cout << "\t|\t\t\t\t|" << endl;
	cout << "\t|\t2.审 核  预 约\t\t|\t" << endl;
	cout << "\t|\t\t\t\t|" << endl;
	cout << "\t|\t0.退 出  登 录\t\t|\t" << endl;
	cout << "\t -------------------------------\t" << endl;
	cout << "输入你选择的操作：";
}
//查看所有预约   ---   查看全部预约信息以及预约状态
void Teacher::showAllOrder()
{
	OrderFile of;
	//ifstream ifs;
	//ifs.open(ORDER_FILE,ios::in);
	if (of.m_Size == 0)
	{
		cout << "现在还没有预约信息" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (map<int, map<string, string>>::iterator it = of.m_orderData.begin(); it != of.m_orderData.end(); it++)
	{
		cout << it->first + 1 << "、";
		int i = 1;
		for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
		{
			if (i == 1)
			{
				cout << "星期";
				cout << mit->second << " ";
			}
			else if (i == 2)
			{
				cout << "时段：" << "";
				cout << ((mit->second) == "1" ? "上午" : "下午") << " ";
			}
			else if (i == 3)
			{
				cout << "机房：";
				cout << mit->second << " ";
			}
			else if (i == 4)
			{
				cout << "状态：";
				if (mit->second == "1")
				{
					cout << "审核中" << " ";
				}
				else if (mit->second == "2")
				{
					cout << "预约成功" << " ";
				}
				else if (mit->second == "-1")
				{
					cout << "预约失败" << " ";
				}
				else
				{
					cout << "已取消" << " ";
				}
			}
			else if (i == 5)
			{
				cout << "学号：";
				cout << mit->second << " ";
			}
			else if (i == 6)
			{
				cout << "姓名：";
				cout << mit->second << " " << endl;
			}
			i++;
		}
	}
	//ifs.close();
	system("pause");
	system("cls");
	
}
//审核预约    ---   对学生的预约进行审核
void Teacher::examineOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << index++ << "、 ";
			cout << "预约日期： 周" << of.m_orderData[i]["date"];
			cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房：" << of.m_orderData[i]["roomId"];
			string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约  -1 预约失败
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "预约成功";
			}
			cout << status << endl;

		}

	}

	cout << "请选择你对哪个预约进行审核,0代表返回" << endl;
	int sel;
	while (true)
	{
		cin >> sel;
		if (sel >= 0 && sel <= v.size())
		{
			if (sel == 0)
			{
				break;
			}
			else
			{
				//	cout << "记录所在位置： " << v[select - 1] << endl;
				int ch;
				cout << "1.通过预约" << endl;
				cout << "2.取消掉这个预约" << endl;
				cin >> ch;
				if (ch == 1 || ch == 2)
				{
					if (ch == 1)
					{
						of.m_orderData[v[sel - 1]]["status"] = "2";
						of.updateOrder();
						cout << "通过成功" << endl;
						break;
					}
					else if (ch == 2)
					{
						of.m_orderData[v[sel - 1]]["status"] = "-1";
						of.updateOrder();
						cout << "已取消预约" << endl;
						break;
					}
				}
				cout << "输入有误，请重新输入" << endl;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");

}