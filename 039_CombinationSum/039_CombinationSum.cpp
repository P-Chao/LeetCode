#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>>res;
	vector<int>ans;
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		if (candidates.empty()) return res;
		dfs(0, 0, target, candidates);
		return res;
	}
	void dfs(int start, int sum, int target, vector<int>& candidates){
		if (sum == target){
			res.push_back(ans);
			return;
		} else if (sum > target){
			return;
		} else{
			for (int i = start; i < candidates.size(); i++){
				ans.push_back(candidates[i]);
				dfs(i, sum + candidates[i], target, candidates);
				ans.pop_back();
			}
		}

	}

	vector<vector<int>> combinationSum_dp_increment(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());

		vector<vector<vector<int>>> dp(target + 1, vector<vector<int>>());
		dp[0].push_back(vector<int>());

		for (const int &candidate : candidates) {
			// all the existing combinations, except for those whose sum exceeds target
			for (int sub_target = 0; sub_target + candidate <= target; ++sub_target){
				vector<vector<int>> new_combinations = dp[sub_target];
				for (vector<int> &new_combination : new_combinations) {  // append a candidate
					new_combination.push_back(candidate);
				}
				int target_yielded = sub_target + candidate;  // the target yielded
				dp[target_yielded].insert(dp[target_yielded].end(), new_combinations.begin(), new_combinations.end());
			}
		}

		return dp[target];
	}
};

int main(int argc, char *argv[]){
	Solution s;
	system("pause");
	return 0;
}