#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		n = nums.size();
		vector<int> ans;
		dfs(-1, nums, ans);
		return res;
	}
private:
	void dfs(int start, vector<int>& nums, vector<int>& ans){
		res.push_back(ans);
		for (int i = start + 1; i < n; ++i){
			ans.push_back(nums[i]);
			dfs(i, nums, ans);
			ans.pop_back();
		}
	}
	vector<vector<int>> res;
	int n;
};

int main(int argc, char *argv[]){
	Solution s;
	auto matrix = s.subsets(vector<int>{1, 4, 9});
	for (auto mat : matrix){
		for (auto m : mat){
			cout << m << ", ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}