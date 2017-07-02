#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<string> a(n, string(n, '.'));
		helper(a, 0, 0, n);
		return ans;
	}
private:
	vector<vector<string>> ans;

	void helper(vector<string>& a, int i, int j, int n){
		if (j == n) {
			ans.push_back(a); return;
		}
		for (int i = 0; i < n; i++){
			if (isValid(a, i, j, n)){
				a[j][i] = 'Q';
				helper(a, 0, j + 1, n);
				a[j][i] = '.';
			}
		}
	}

	bool isValid(vector<string>& a, int i, int j, int n){
		for (int x = 1; j - x >= 0; x++){
			if (a[j - x][i] == 'Q') return false;
			if (i - x >= 0 && a[j - x][i - x] == 'Q') return false;
			if (i + x < n && a[j - x][i + x] == 'Q') return false;
		}
		return true;
	}
};

class SolutionT {
public:
	vector<vector<string>> solveNQueens(int n) {
		return convert(solve(n), n);
	}

private:
	vector<vector<int>> solve(int n){
		vector<vector<int>> ret;
		vector<int> cur;
		Helper(ret, cur, 0, n);
		return ret;
	}

	void Helper(vector<vector<int>>& ret, vector<int> cur, int pos, int n){
		if (pos == n){
			ret.push_back(cur);
		} else{
			for (int i = 0; i < n; ++i){
				cur.push_back(i);
				if (check(cur)){
					Helper(ret, cur, pos+1, n);
				}
				cur.pop_back();
			}
		}
		return;
	}

	bool check(vector<int> cur){
		int size = cur.size();
		int loc = cur[size-1];
		for (int i = 0; i < size - 1; ++i){
			if (cur[i] == loc || (abs(cur[i] - loc) == abs(i - size + 1))){
				return false;
			}
		}
		return true;
	}

	vector<vector<string>> convert(vector<vector<int>> ret, int n){
		vector<vector<string>> resStr;
		for (int i = 0; i < ret.size(); ++i){
			vector<string> curStr;
			for (int j = 0; j < n; ++j){
				string loc(n, '.');
				loc[ret[i][j]] = 'Q';
				curStr.push_back(loc);
			}
			resStr.push_back(curStr);
		}
		return resStr;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto block = s.solveNQueens(4);
	for (auto matrix : block){
		for (auto line : matrix){
			cout << line << endl;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}