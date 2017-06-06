#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		n = nums.size();
		vector<int> ans;
		sort(nums.begin(), nums.end());
		dfs(0, ans, nums);
		return res;
	}

private:
	void dfs(int start, vector<int>& ans,vector<int>& nums){
		res.push_back(ans);
		for (int i = start; i < n; ++i){
			if (i != start && nums[i] == nums[i - 1]){
				continue;
			}
			ans.push_back(nums[i]);
			dfs(i + 1, ans, nums);
			ans.pop_back();
		}
	}
	vector<vector<int>> res;
	int n;
};

int main(int argc, char *argv[]){
	Solution s;
	auto subsets = s.subsetsWithDup(vector<int>{1, 2, 2});
	for (auto vv : subsets){
		for (auto v : vv){
			cout << v << ", ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}