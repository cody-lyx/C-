#include<iostream>
#include<vector>
using namespace std;
string Array(string s, int numRows);
int main()
{
	string s = "LEETCODEISHIRING";
	string s2 = Array(s, 3);
	cout << s2;
}
string Array(string s, int numRows)
{
    if (numRows == 1) return s;
    vector<string> rows(min(numRows, int(s.size())));//创建一个容器，用来直接存储排列好后每行字符。row[0]存储Z字形排列后第一行所有字符，以此类推
    int curRow = 0;
    bool goingDown = false;//判断方向是否改变
    
    for (char c : s) {
        rows[curRow] += c;
        if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
        curRow += goingDown ? 1 : -1;
    }
    string ret;
    for (string row : rows) ret += row;
    return ret;
}
