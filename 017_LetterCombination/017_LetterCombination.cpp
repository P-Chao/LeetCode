#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> table = { " ", "@", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0){
			return{};
		}
		dfs(digits);
		return res;
	}

private:
	void dfs(string& digits){
		if (digits.size() == 0){
			res.push_back(ans);
			return;
		}
		char t = digits[0];
		string dgt = digits.substr(1);
		if (t == '*' || t == '#'){
			ans.push_back(t);
			dfs(dgt);
			ans.pop_back();
		} else{
			t -= '0';
			for (int i = 0; i < table[t].size(); ++i){
				ans.push_back(table[t][i]);
				dfs(dgt);
				ans.pop_back();
			}
		}
		return;
	}
	vector<string> res;
	string ans;
};

int main(int argc, char *argv[]){
	Solution s;
	auto vs = s.letterCombinations("23");
	for (auto s : vs){
		cout << s << ", ";
	}
	cout << endl;
	system("pause");
	return 0;
}