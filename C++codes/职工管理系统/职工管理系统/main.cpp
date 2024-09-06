//-----------------------------------------------------------------------------
// *********************         职工管理系统         **************************
//-----------------------------------------------------------------------------
// *********************        0.退出管理程序        **************************
// *********************        1.增加职工信息        **************************
// *********************        2.显示职工信息        **************************
// *********************        3.删除离职职工        **************************
// *********************        4.修改职工信息        **************************
// *********************        5.查找职工信息        **************************
// *********************        6.按照编号排序        **************************
// *********************        7.清空所有文档        **************************
//-----------------------------------------------------------------------------


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


class Employee
{
public:
	enum class EmployeeType
	{
		COMMON,
		MANAGER,
		BOSS
	};

public:
	int id;
	string name;
	int level;
};

class Company
{
public:
	vector<Employee> employees_list;
};


void menu()
{
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << " *********************         职工管理系统         **************************" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << " *********************        0.退出管理程序        **************************" << endl;
	cout << " *********************        1.增加职工信息        **************************" << endl;
	cout << " *********************        2.显示职工信息        **************************" << endl;
	cout << " *********************        3.删除离职职工        **************************" << endl;
	cout << " *********************        4.修改职工信息        **************************" << endl;
	cout << " *********************        5.查找职工信息        **************************" << endl;
	cout << " *********************        6.按照编号排序        **************************" << endl;
	cout << " *********************        7.清空所有文档        **************************" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
}

void write_infomation_into_file(Company& company)
{
	ofstream ofs("employees_list.txt", ios::out);

	ofs << company.employees_list.size() << endl;
	for (Employee employee : company.employees_list)
		ofs << employee.id << " " << employee.name << " " << employee.level << endl;

	ofs.close();
}

void exit_system()
{
	cout << "退出成功" << endl;
	exit(0);
}

void add_employee_infomation(Company& company)
{
	int add_num;
	cout << "需要添加的人数：";
	cin >> add_num;

	for(int i = 0; i < add_num; i++) {
		Employee new_employee;

		cout << "请输入员工 id ：";
		cin >> new_employee.id;
		cout << "请输入员工 姓名 ：";
		cin >> new_employee.name;
		cout << "请输入员工 级别 ：";
		cin >> new_employee.level;

		company.employees_list.push_back(new_employee);

		cout << "第" << i + 1 << "个员工添加完成" << endl;
	}

	write_infomation_into_file(company);

	cout << "所有员工添加完成，当前职工数量为 " << company.employees_list.size() << " 人" << endl;

	system("pause");
	system("cls");
}

void show_employee_infomation(const Company& company)
{
	cout << "当前职工总人数：" << company.employees_list.size() << endl;
	for (Employee employee : company.employees_list)
	{
		cout << "id = " << employee.id << " name = " << employee.name << " level = " << employee.level << endl;
	}

	system("pause");
	system("cls");
}

void delete_departing_employee(Company& company)
{
	int input;
	int input_id;
	string input_name;

	cout << "0.退出" << endl;
	cout << "1.按 id 删除" << endl;
	cout << "2.按 name 删除" << endl;
	cout << "请输入：" << endl;

	cin >> input;

	switch (input)
	{
	case 0:
		cout << "退出" << endl;
		break;
	case 1:
		cout << "请输入要删除的员工的 id :";
		cin >> input_id;

		for (int i = 0; i < company.employees_list.size(); i++)
		{
			if (company.employees_list[i].id == input_id) {
				company.employees_list.erase(company.employees_list.begin() + i);

				write_infomation_into_file(company);

				cout << "删除成功，当前职工数量为 " << company.employees_list.size() << " 人" << endl;

				system("pause");
				system("cls");

				return;
			}
		}

		cout << "未找到该 id 号的员工" << endl;

		break;
	case 2:
		cout << "请输入要删除的员工的 name :";
		cin >> input_name;

		for (int i = 0; i < company.employees_list.size(); i++)
		{
			if (company.employees_list[i].name.compare(input_name))
			{
				company.employees_list.erase(company.employees_list.begin() + i);

				write_infomation_into_file(company);

				cout << "删除成功，当前职工数量为 " << company.employees_list.size() << " 人" << endl;

				system("pause");
				system("cls");

				return;
			}
		}

		cout << "未找到该 id 号的员工" << endl;

		break;
	default:
		cout << "输入错误" << endl;
		break;
	}

	system("pause");
	system("cls");
}

void modify_employee_infomation(Company& company)
{
	int input;
	int input_id;
	string input_name;

	cout << "0.退出" << endl;
	cout << "1.按 id 查找" << endl;
	cout << "2.按 name 查找" << endl;
	cout << "请输入：" << endl;
	
	cin >> input;

	switch (input)
	{
	case 0:
		cout << "退出" << endl;
		break;
	case 1:
		cout << "请输入要修改的员工的 id ";
		cin >> input_id;

		for (int i = 0; i < company.employees_list.size(); i++)
		{
			Employee& employee = company.employees_list[i];
			if (employee.id == input_id)
			{
				cout << "已找到需要修改的员工" << endl;
				cout << "请输入员工 id ：";
				cin >> employee.id;
				cout << "请输入员工 姓名 ：";
				cin >> employee.name;
				cout << "请输入员工 级别 ：";
				cin >> employee.level;

				cout << "信息修改成功！" << endl;

				write_infomation_into_file(company);

				system("pause");
				system("cls");

				return;
			}
		}
		
		break;
	case 2:
		cout << "请输入要修改的员工的 name ";
		cin >> input_name;

		for (int i = 0; i < company.employees_list.size(); i++)
		{
			Employee& employee = company.employees_list[i];
			if (employee.name.compare(input_name))
			{
				cout << "已找到需要修改的员工" << endl;
				cout << "请输入员工 id ：";
				cin >> employee.id;
				cout << "请输入员工 姓名 ：";
				cin >> employee.name;
				cout << "请输入员工 级别 ：";
				cin >> employee.level;

				cout << "信息修改成功！" << endl;

				write_infomation_into_file(company);

				system("pause");
				system("cls");

				return;
			}
		}
		
		break;
	default:
		cout << "输入错误" << endl;
		break;
	}

	system("pause");
	system("cls");
}

void search_employee_infomation(Company& company)
{
	int input;
	int input_id;
	string input_name;

	cout << "0.退出" << endl;
	cout << "1.按 id 查找" << endl;
	cout << "2.按 name 查找" << endl;
	cout << "请输入：" << endl;

	cin >> input;

	switch (input)
	{
	case 0:
		cout << "退出" << endl;
		break;
	case 1:
		cout << "请输入要查找的员工的 id ";
		cin >> input_id;

		for (int i = 0; i < company.employees_list.size(); i++)
		{
			Employee& employee = company.employees_list[i];
			if (employee.id == input_id)
			{
				cout << "已找到需要查找的员工" << endl;
				cout << "id ：" << employee.id;
				cout << " 姓名 ：" << employee.name;
				cout << " 级别 ：" << employee.level << endl;

				system("pause");
				system("cls");

				return;
			}
		}

		cout << "未找到该员工" << endl;

		break;
	case 2:
		cout << "请输入要查找的员工的 name ";
		cin >> input_name;

		for (int i = 0; i < company.employees_list.size(); i++)
		{
			Employee& employee = company.employees_list[i];
			if (employee.name.compare(input_name))
			{
				cout << "已找到需要查找的员工" << endl;
				cout << "id ：" << employee.id;
				cout << " 姓名 ：" << employee.name;
				cout << " 级别 ：" << employee.level << endl;

				system("pause");
				system("cls");

				return;
			}
		}

		cout << "未找到该员工" << endl;

		break;
	default:
		cout << "输入错误" << endl;
		break;
	}

	system("pause");
	system("cls");
}

void sort_by_id(Company& company)
{
	for (int i = 0; i < company.employees_list.size() - 1; i++)
	{
		for (int j = 0; j < company.employees_list.size() - 1 - i; j++)
		{
			if (company.employees_list[j].id > company.employees_list[j + 1].id)
			{
				Employee temp_employee = company.employees_list[j];
				company.employees_list[j] = company.employees_list[j + 1];
				company.employees_list[j + 1] = temp_employee;
			}
		}
	}

	cout << "排序成功" << endl;

	cout << "当前职工总人数：" << company.employees_list.size() << endl;
	for (Employee employee : company.employees_list)
		cout << "id = " << employee.id << " name = " << employee.name << " level = " << employee.level << endl;

	write_infomation_into_file(company);

	system("pause");
	system("cls");
}

void clear_all_ducuments()
{
	ofstream ofs("employees_list.txt", ios::out);

	ofs.close();

	cout << "员工文件已清空" << endl;

	system("pause");
	system("cls");
}

void workforce_management_system()
{
	Company company;

	ifstream ifs("employees_list.txt", ios::in);

	if (ifs.is_open())
	{
		int employee_num = 0;
		ifs >> employee_num;
		company.employees_list.resize(employee_num);

		for (Employee& employee : company.employees_list)
			ifs >> employee.id >> employee.name >> employee.level;

		ifs.close();
	}

	int input;

	while (1) {
		menu();
		cout << "请输入：";
		cin >> input;

		switch (input)
		{
		case 0:		exit_system();							break;
		case 1:		add_employee_infomation(company);		break;
		case 2:		show_employee_infomation(company);		break;
		case 3:		delete_departing_employee(company);		break;
		case 4:		modify_employee_infomation(company);	break;
		case 5:		search_employee_infomation(company);	break;
		case 6:		sort_by_id(company);					break;
		case 7:		clear_all_ducuments();					break;
		default: break;
		}
	}
}

int main()
{
	workforce_management_system();

	return 0;
}