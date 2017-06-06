#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		int len = s.size();
		if (len < 4 || len > 12){
			return{};
		}
		vector<string> ans;
		dfs(s, ans);
		return res;
	}
private:
	void dfs(string s, vector<string>& ans){
		int req = 3 - ans.size();
		if (req == 0){
			int l = atoi(s.c_str());
			if (s.size() != 1 && s[0] == '0' || l > 255){
				return;
			}
			res.push_back(ans[0] + ans[1] + ans[2] + s);
			return;
		}
		for (int i = 1; i < 4; ++i){
			int remain = s.size() - i;
			if (remain < req || remain > 3 * req){
				continue;
			}
			int l = atoi(s.substr(0, i).c_str());
			if (l > 255){
				continue;
			}
			if (i > 1 && s[0] == '0'){
				continue;
			}
			ans.push_back(s.substr(0, i) + ".");
			dfs(s.substr(i), ans);
			ans.pop_back();
		}
	}
	vector<string> res;
};

int main(int argc, char *argv[]){
	Solution s;
	auto vs = s.restoreIpAddresses("255255255255");
	for (auto s : vs){
		cout << s << endl;
	}
	system("pause");
	return 0;
}
