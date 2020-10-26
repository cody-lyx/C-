#include"method.h"
#include<iostream>
#include<string>

int main()
{
	method1();
	int x1(5), x2(3);
	int x = method2(x1, x2);
	std::cout << "这是第二个函数，执行的结果为：" << x << std::endl;
	std::cout << "How many student ? Please input" << std::endl;
	int Student_Number_int;

	std::cin >> Student_Number_int;	//输入录入名字人数

	student* all_student = new student[Student_Number_int];


	for (int i = 0; i < Student_Number_int; i++)
	{
	
		std::string name_string;	//姓名
		std::string id_string;		//学号
		int age_int;				//年龄
		std::cout << "请输入姓名："; std::cin >> name_string;
		std::cout << "请输入学号："; std::cin >> id_string;
		std::cout << "请输入年龄："; std::cin >> age_int;
		all_student[i] = student(name_string, id_string, age_int);
		std::cout << "\n";

	}
	std::cout << "按任意键继续。。。。\n" << std::endl;
	std::cin.get();

	for (int i = 0; i < Student_Number_int; i++)
	{
		all_student[i].Print();
	}
	
	return 0;
}
