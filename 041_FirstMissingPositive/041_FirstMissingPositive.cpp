#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		const int n = nums.size();
		int i = 0;
		while (i < n){
			if (nums[i] != i + 1 && nums[i] >= 1 && nums[i] <= n 
				&& nums[nums[i] - 1] != nums[i]){ // 防止死循环，交换的两个数相等，则一直满足交换条件
				swap(nums[i], nums[nums[i]-1]);
			} else{
				++i;
			}
		}
		for (i = 0; i < n; ++i){
			if (nums[i] != i + 1){
				return i + 1;
			}
		}
		return i + 1;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.firstMissingPositive(vector<int>{1, 2, 3, 1, 1, 1}) << endl;
	system("pause");
	return 0;
}