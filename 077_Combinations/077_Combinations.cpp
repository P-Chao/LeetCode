#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		dfs(0, n, k);
		return res;
	}

private:
	void dfs(int start, int n, int depth){
		if (!depth){
			res.push_back(ans);
		}
		for (int i = start+1; i <= n; ++i){
			ans.push_back(i);
			dfs(i, n, depth-1);
			ans.pop_back();
		}
	}
	vector<int> ans;
	vector<vector<int>> res;
};

int main(int argc, char *argv[]){
	Solution s;
	auto res = s.combine(4, 2);
	for (auto vv : res){
		for (auto v : vv){
			cout << v << ", ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}