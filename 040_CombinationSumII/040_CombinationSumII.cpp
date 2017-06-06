#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<int>tmp;
		dfs(candidates, target, tmp, 0);
		return s;
	}
private:

	void dfs(vector<int>& candidates, int target, vector<int>&tmp, int cur){
		if (target < 0) return;
		if (target == 0){
			s.push_back(tmp);
			return;
		}
		for (int i = cur; i < candidates.size(); i++){
			if (cur != i&&candidates[i] == candidates[i - 1]) continue;//i-1,i  
			tmp.push_back(candidates[i]);
			dfs(candidates, target - candidates[i], tmp, i + 1);
			tmp.pop_back();
		}
	}

	vector<vector<int> > s;
};

int main(int argc, char *argv[]){
	Solution s;
	system("pause");
	return 0;
}