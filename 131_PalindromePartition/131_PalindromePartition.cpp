#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {
		const int n = s.size();
		vector<vector<bool>> palin(n, vector<bool>(n, false));
		for (int i = 0; i < n; ++i){
			palin[i][i] = true;
		}
		for (int i = 0; i < n - 1; ++i){
			int j = i + 1;
			palin[i][j] = (s[i] == s[j]);
		}
		for (int len = 2; len < n; ++len){
			for (int i = 0; i < n - len; ++i){
				int j = i + len;
				palin[i][j] = (s[i] == s[j]) && palin[i+1][j-1];
			}
		}
		
		vector<pair<int, int>> chain;
		backtrack(0, n, chain, palin);

		vector<vector<string>> result;
		for (auto sv : record){
			vector<string> ans;
			for (auto sp : sv){
				ans.push_back(s.substr(sp.first, sp.second - sp.first + 1));
			}
			result.push_back(ans);
		}

		return result;
	}

private:
	void backtrack(int start, int bound, vector<pair<int, int>>& chain, vector<vector<bool>>& palin){
		if (start == bound){
			record.push_back(chain);
			return;
		}

		for (int i = start; i < bound; ++i){
			if (palin[start][i]){
				chain.push_back({ start, i });
				backtrack(i + 1, bound, chain, palin);
				chain.pop_back();
			}
		}
		return;
	}
	vector<vector<pair<int, int>>> record;
};

int main(int argc, char *argv[]){
	Solution s;
	auto vvs = s.partition("aab"); // "a" "a" "b"; "aa" "b";
	for (auto vv : vvs){
		for (auto v : vv){
			cout << v << ", ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}