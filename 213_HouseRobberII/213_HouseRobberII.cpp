#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		const int n = nums.size();
		if (n == 0){
			return 0;
		}
		if (n == 1){
			return nums[0];
		}
		
		int cur = nums[0];
		int prev = nums[0];
		int pprev = 0;
		for (int i = 1; i < n - 1; ++i){
			cur = max(prev, pprev + nums[i]);
			pprev = prev;
			prev = cur;
		}

		int cur2 = nums[1];
		prev = nums[1];
		pprev = 0;
		for (int i = 2; i < n; ++i){
			cur2 = max(prev, pprev + nums[i]);
			pprev = prev;
			prev = cur2;
		}
		
		return max(cur, cur2);
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.rob(vector<int>{2, 7, 9, 3, 1}) << endl;
	system("pause");
	return 0;
}
