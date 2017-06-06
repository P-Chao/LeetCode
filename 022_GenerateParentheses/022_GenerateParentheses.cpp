#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		if (n < 1){
			return{};
		}
		dfs(string(""), n, n);
		return res;
	}

private:
	void dfs(string s, int l, int r){
		if (l == 0 && r == 0){
			res.push_back(s);
			return;
		}
		if (l > 0){
			dfs(s + "(", l-1, r);
		}
		if (r > l){
			dfs(s + ")", l, r-1);
		}
	}
	vector<string> res;
};

int main(int argc, char *argv[]){
	Solution s;
	auto vs = s.generateParenthesis(3);
	for (auto s : vs){
		cout << s << endl;
	}
	system("pause");
	return 0;
}