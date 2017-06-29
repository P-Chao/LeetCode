#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		n = nums.size();
		vector<bool> mask(n, true);
		dfs(nums, mask, 0);
		return res;
	}
private:
	void dfs(vector<int>& nums, vector<bool>& mask, int depth){
		if (depth == n){
			res.push_back(ans);
			return;
		}
		bool flag = false;
		int prev = nums[0];
		for (int i = 0; i < n; ++i){
			if (mask[i]){
				if (nums[i] == prev && flag){	
					continue;
				}
				flag = true;
				mask[i] = false;
				ans.push_back(nums[i]);
				prev = nums[i];
				dfs(nums, mask, depth + 1);
				ans.pop_back();
				mask[i] = true;
			}
		}
	}
	int n;
	vector<int> ans;
	vector<vector<int>> res;
};

int main(int argc, char *argv[]){
	Solution s;
	auto matrix = s.permuteUnique(vector<int>{1, 1, 2});
	for (auto line : matrix){
		for (auto v : line){
			cout << v << ", ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}