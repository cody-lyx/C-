#pragma once
const int MaxSize = 100;
class SeqList
{
public:
	SeqList() { length = 0; }
	SeqList(int a[], int n);
	~SeqList() {};
	int Length() { return length; }
	int Get(int i);
	int Locate(int x);
	void Insert(int i, int x);
	int Delete(int i);
	void PrintList();
	friend SeqList Add(SeqList A, SeqList B);

private:
	int date[MaxSize];
	int length;
};
