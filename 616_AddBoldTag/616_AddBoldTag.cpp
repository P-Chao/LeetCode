#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string addBoldTag(string s, vector<string>& dict) {
		int n = s.size();
		vector<int> open(n + 1), closed(n + 1);
		for (string & w : dict) {
			int i = -1;
			while ((i = s.find(w, i + 1)) != string::npos) {
				++open[i];
				++closed[i + w.size()];
			}
		}
		string tagged;
		int pre = 0;
		for (int i = 0, t = 0; i <= n; ++i) {
			if (open[i] && 0 == t && !closed[i]) {
				tagged += s.substr(pre, i - pre) + "<b>";
				pre = i;
			}
			t += open[i];
			t -= closed[i];
			if (closed[i] && 0 == t && !open[i]) {
				tagged += s.substr(pre, i - pre) + "</b>";
				pre = i;
			}
		}
		return tagged + s.substr(pre);
	}

	string addBoldTagMy(string s, vector<string>& dict) {
		const int dic_sz = dict.size();
		const int n = s.size();
		vector<bool> mask(n, false);
		for (int i = 0; i < dic_sz; ++i){
			int len = dict[i].size();
			for (int j = 0; j <= n - len; ++j){
				if (s.substr(j, len) == dict[i]){
					for (int k = 0; k < len; ++k){
						mask[j + k] = true;
					}
				}
			}
		}
		string res;
		for (int i = 0; i < n; ++i){
			if (mask[i]){
				if (i == 0 || mask[i-1] == false){
					res += "<b>";
				}
				res = res + s[i];
				if ((i == n - 1) || (mask[i+1] == false)){
					res = res + "</b>";
				}
			} else{
				res = res + s[i];
			}
		}
		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.addBoldTag("abcxyz123", vector<string>{"abc", "123"}) << endl;
	system("pause");
	return 0;
}