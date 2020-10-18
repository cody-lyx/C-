#include<iostream>
#include"method.h"
#include<string>

void method1()
{
	std::cout << "这是第一个函数,啥也不执行" << std::endl;
}

int method2(int x1, int x2)
{
	std::cout << "这是第二个函数" << std::endl;
	return x1 + x2;
}


//student类中的实现

student::student(std::string name, std::string id, int age)
{
	name_string = name;
	id_string = id;
	age_int = age;
}

void student::Print()
{

	std::cout << "姓名：" << name_string << std::endl;
	std::cout << "学号：" << id_string << std::endl;
	std::cout << "年龄：" << age_int << std::endl;
	std::cout << "--------------------------------------\n\n" << std::endl;

}
