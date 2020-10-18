#include<string>

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
