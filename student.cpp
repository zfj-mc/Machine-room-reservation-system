#include"student.h"


Student::Student()
{

}
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	ifstream ifs;
	ifs.open(COMPUTERROOM_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
}

//显示Student子菜单
void Student::operMenu()
{
	cout << "欢迎同学登录" << endl;
	cout << "\t -------------------------------\t" << endl;
	cout << "\t|\t1.申 请  预 约\t\t|\t" << endl;
	cout << "\t|\t\t\t\t|" << endl;
	cout << "\t|\t2.查看自身预约\t\t|\t" << endl;
	cout << "\t|\t\t\t\t|" << endl;
	cout << "\t|\t3.查看所有预约\t\t|\t" << endl;
	cout << "\t|\t\t\t\t|" << endl;
	cout << "\t|\t4.取 消  预 约\t\t|\t" << endl;
	cout << "\t|\t\t\t\t|" << endl;
	cout << "\t|\t0.退 出  登 录\t\t|\t" << endl;
	cout << "\t -------------------------------\t" << endl;
	cout << "输入你选择的操作：" << endl;

}
// 申请预约 --- 预约机房
void Student::applyOrder()
{
	cout << "机房可供预约的时间段为周一至周五，请选择你想要预约的时间：" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;

	int date = 0;//日期
	int interval = 0;//时间段
	int room = 0;
	while (true)
	{
		cin >> date;
		if (date >= 1 || date <= 5)
		{
			break;
		}
		else
		{
			cout << "请规范输入：" << endl;;
		}
	}
	cout << "请选择你要预约的时间段：" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval == 1 || interval == 2)
		{
			break;
		}
		else
		{
			cout << "请规范输入：" << endl;;
		}
	}
	cout << "请选择你要预约的机房：" << endl;
	cout << "1.一号机房 容量：20" << endl;
	cout << "2.一号机房 容量：50" << endl;
	cout << "3.一号机房 容量：100" << endl;
	while (true)
	{
		cin >> room;
		if (room == 1 || room == 2 || room == 3)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	cout << "预约成功！审核中" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close();
	system("pause");
	system("cls");
	
}
// 查看自身的预约 --- 查看自己的预约状态
void Student::showMyOrder()
{
	OrderFile of;
	//ifstream ifs;
	//ifs.open(ORDER_FILE, ios::in);
	if (of.m_Size == 0)
	{
		cout << "现在还没有预约信息" << endl;
		system("pause");
		system("cls");
		return;
	}
	int j = 1;

	for (map<int, map<string, string>>::iterator it = of.m_orderData.begin(); it != of.m_orderData.end(); it++)
	{
		int i = 1;

		for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
		{

			if (mit->second == to_string(this->m_Id))
			{
				cout << j << "、";
				for (map<string, string>::iterator Mit = it->second.begin(); Mit != it->second.end(); Mit++)
				{
					if (i == 1)
					{
						cout << "星期";
						cout << Mit->second << " ";
					}
					else if (i == 2)
					{
						cout << "时段：" << "";
						cout << ((Mit->second) == "1" ? "上午" : "下午") << " ";
					}
					else if (i == 3)
					{
						cout << "机房：";
						cout << Mit->second << " ";
					}

					else if (i == 4)
					{
						cout << "状态：";
						if (Mit->second == "1")
						{
							cout << "审核中" << endl;
						}
						else if (Mit->second == "2")
						{
							cout << "预约成功" << endl;
						}
						else if (Mit->second == "-1")
						{
							cout << "预约失败" << endl;
						}
						else
						{
							cout << "已取消" << endl;
						}
					}

					i++;
				}
				j++;
			}

		}
	}

	//ifs.close();
	system("pause");
	system("cls");
}
	
// 查看所有预约 --- 查看全部预约信息以及预约状态
void Student::showAllOrder()
{
	OrderFile of;

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
// 取消预约 --- 取消自身的预约，预约成功或审核中的预约均可取消
void Student::cancelOrder()
{
	
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;

	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)
		{
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
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
	}

	cout << "请输入取消的记录,0代表返回" << endl;
	cout << v.size() << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				//	cout << "记录所在位置： " << v[select - 1] << endl;
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "已取消预约" << endl;
				break;
			}

		}
		cout << "输入有误，请重新输入" << endl;
	}

	system("pause");
	system("cls");
	

}