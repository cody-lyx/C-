#include<iostream>
#include<vector>
#include<algorithm>   //要使用vector中sort自动排序方法，必须调用这个文件。
using namespace std;
/*
解析：
首先对数组进行排序，排序后固定一个数 nums[i]，再使用左右指针指向 nums[i]后面的两端，数字分别为 nums[k]和nums[j]，计算三个数的和sum判断是否满足为0，满足则添加进结果集
如果nums[i]大于0，则三数之和必然无法等于 00，结束循环
如果nums[i] == nums[i-1]，则说明该数字重复，会导致结果重复，所以应该跳过
当 sum == 0 时，nums[k] == nums[k+1] 则会导致结果重复，应该跳过，k++
当 sum == 0 时，nums[j] == nums[j−1] 则会导致结果重复，应该跳过，j−−
*/
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>>result;
	if (nums.size() < 3)
		return result;
	sort(nums.begin(), nums.end());
	if (nums[0] > 0 || nums[nums.size() - 1] < 0)
		return result;
	int i(0), j(nums.size() - 1), k;
	vector<int>m;
	while (nums[i] <= 0 && i < nums.size() - 2) {
		if (i > 0 && nums[i] == nums[i - 1]) {  //如果nums[i] == nums[i-1]，则说明该数字重复，会导致结果重复，所以应该跳过
			i++;
			continue;
		}
		k = i + 1;
		j = (nums.size() - 1);
    
		while (k < j) {
			if (nums[i] + nums[k] + nums[j] > 0) {
				j--; continue;
			}
      
			if (nums[i] + nums[k] + nums[j] < 0) {
				k++; continue;
			}
      
			if (nums[i] + nums[j] + nums[k] == 0) {
				m.push_back(nums[i]);
				m.push_back(nums[k]);
				m.push_back(nums[j]);
				result.push_back(m);
				m.clear();
			}
			do {  //当 sum == 0 时，nums[k] == nums[k+1] 则会导致结果重复，应该跳过，k++
				k++;
			} while (nums[k] == nums[k - 1] && k < j);
			do {  //当 sum == 0 时，nums[j] == nums[j−1] 则会导致结果重复，应该跳过，j−−
				j--;
			} while (nums[j] == nums[j + 1] && k < j);
		}
    
		i++;
	}
	return result;
}

int main() {
	vector<int>a{ -1,0,1,2,-1,-4,-2,-3,3,0,4 };
	vector<vector<int>>b = threeSum(a);
	cout << b[0][0];
}
