
#include<string>

#ifndef _METHOD_H 	//避免出现多个文件夹里调用头文件产生重定义的错误
#define _METHOD_H	//避免出现多个文件夹里调用头文件产生重定义的错误

void method1();
int method2(int x1, int x2);
class student 
{
public:
	student() {};
	student(std::string name, std::string id, int age);
	void Print();

private:
	std::string name_string;	//姓名
	std::string id_string;		//学号
	int age_int;				//年龄
};
#endif 		//避免出现多个文件夹里调用头文件产生重定义的错误
