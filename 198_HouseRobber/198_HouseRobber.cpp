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
		int cur = nums[0], prev = nums[0], pprev = 0;
		for (int i = 1; i < n; ++i){
			cur = max(pprev + nums[i], prev);
			pprev = prev;
			prev = cur;
		}
		return cur;
	}

	int robNSpace(vector<int>& nums) {
		const int n = nums.size();
		if (n == 0){
			return 0;
		}
		vector<int> dp(n+1, 0);
		dp[1] = nums[0];
		for (int i = 1; i < n; ++i){
			dp[i + 1] = max(dp[i - 1] + nums[i], dp[i]);
		}
		return dp[n];
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.rob(vector<int>{1, 2, 3, 4, 5, 6, 7, 7, 6, 7, 7, 3, 6, 4, 7}) << endl;
	system("pause");
	return 0;
}