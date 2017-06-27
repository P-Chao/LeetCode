#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<int> dp(target+1, 0);
		dp[0] = 1;
		for (int i = 1; i <= target; ++i){
			for (auto a : nums){
				if (i >= a){
					dp[i] += dp[i - a];
				}
			}
		}
		return dp.back();
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.combinationSum4(vector<int>{1, 2, 3}, 32) << endl;
	system("pause");
	return 0;
}