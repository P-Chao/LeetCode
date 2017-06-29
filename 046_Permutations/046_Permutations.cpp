#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
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
		for (int i = 0; i < n; ++i){
			if (mask[i]){
				ans.push_back(nums[i]);
				mask[i] = false;
				dfs(nums, mask, depth+1);
				mask[i] = true;
				ans.pop_back();
			}
		}
	}
	int n;
	vector<int> ans;
	vector<vector<int>> res;
};

int main(int argc, char *argv[]){
	Solution s;
	auto matrix = s.permute(vector<int>{1, 2, 3});
	for (auto line : matrix){
		for (auto v : line){
			cout << v << ", ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}