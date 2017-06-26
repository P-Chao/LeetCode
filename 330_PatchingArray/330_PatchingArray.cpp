#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minPatches(vector<int>& nums, int n) { // 贪心算法
		long miss = 1; // 当前已完成[0, miss)所有组合, 因为是开区间，所以miss可能溢出
		int ret = 0, i = 0; 
		while (miss <= n){
			if (i < nums.size() && nums[i] <= miss){ // nums[i] <= miss时，增加nums[i],可以使组合范围扩大到[0, miss+nums[i])
				miss += nums[i++];
			} else{ // nums[i] > miss 时，增加miss，可以使范围扩大到[0, 2*miss)
				miss <<= 1;
				++ret;
			}
		}
		return ret;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.minPatches(vector<int>{1, 5, 10}, 20) << endl;
	system("pause");
	return 0;
}
