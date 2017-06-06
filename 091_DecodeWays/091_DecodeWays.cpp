#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
	int numDecodings(string s){
		const int n = s.size();
		if (n == 0 || s[0] == '0'){
			return 0;
		} else if(n == 1){
			return 1;
		}
		int pprev = 1;
		int prev = 1;
		int cur = 1;
		for (int i = 1; i < n; ++i){
			int num = atoi(s.substr(i - 1, 2).c_str());
			if (s[i] == '0' && (s[i - 1] == '0' || num > 26)){
				return 0;
			}
			if (num <= 26){
				if (s[i] == '0'){
					cur = pprev;
					prev = cur;
				} else if (s[i-1] != '0'){
					cur += pprev;
				}
			}
			pprev = prev;
			prev = cur;
		}
		return cur;
	}

	int numDecodingsMyDFS(string s) { // TLE
		const int n = s.size();
		if (n == 0){
			return 0;
		}
		res = 0;
		dfs(s);
		return res;
	}
private:
	void dfs(string s){
		if (s.empty()){
			res++;
			return;
		}
		if (s[0] == '0'){
			return;
		}
		dfs(s.substr(1));
		if (s.size() > 1 && atoi(s.substr(0, 2).c_str()) <= 26){
			dfs(s.substr(2));
		}
	}
	int res;
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.numDecodings("110") << endl;
	system("pause");
	return 0;
}