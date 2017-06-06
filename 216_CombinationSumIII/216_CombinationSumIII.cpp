#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		dpth = k;
		dfs(0, n, 0);
		return res;
	}
private:
	void dfs(int start, int target, int deepth){
		if (deepth == dpth && target == 0){
			res.push_back(ans);
			return;
		}
		if (deepth >= dpth || target < 0){
			return;
		}
		for (int i = start + 1; i < 10; ++i){
			ans.push_back(i);
			dfs(i, target-i, deepth+1);
			ans.pop_back();
		}
	}
	int dpth;
	vector<int> ans;
	vector<vector<int>> res;
};

int main(int argc, char *argv[]){
	Solution s;
	auto vv = s.combinationSum3(3, 9);
	for (auto v : vv){
		for (auto r : v){
			cout << r << ", ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}