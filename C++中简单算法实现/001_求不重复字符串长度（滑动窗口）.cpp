#include<iostream>
#include<vector>;
using namespace std;

int main()
{
	string s = "pwwkew";
	vector<char> test;//利用容器vector解决
	int MaxSize(0), n(1);
	for (int i = 0; i < s.length(); i++)
	{
		test.push_back(s[i]);
		//cout << test.size();
		n = test.size();
		for (int j = 0; j < n-1; j++)
		{
			if (test[j] == s[i])
			{
				test.erase(test.begin(), test.begin() + (j + 1));
				break;
			}
		}
		n = test.size();
		MaxSize = max(MaxSize, n);
	}
	cout << MaxSize << endl;
}
//此题利用滑动窗口思想解决
