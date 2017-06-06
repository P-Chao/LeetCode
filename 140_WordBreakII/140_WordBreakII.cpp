#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
	int minLen, maxLen;
	unordered_set<string> dict;
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		dict.clear();
		minLen = INT_MAX; maxLen = 0;
		for (auto& w : wordDict) {
			minLen = min(minLen, (int)w.size());
			maxLen = max(maxLen, (int)w.size());
			dict.insert(w);
		}
		int n = s.size();
		vector<bool> canBreak(n + 1, false);
		canBreak[0] = true;
		for (int i = minLen; i <= n; ++i) {
			for (int l = minLen; l <= min(maxLen, i); ++l) {
				string t = s.substr(i - l, l);
				if (dict.count(t) && canBreak[i - l]) {
					canBreak[i] = true;
					break;
				}
			}
		}
		if (!canBreak[n]) return{};
		vector<string> ans;
		string tmp;
		dfs(s, 0, ans, tmp);
		return ans;
	}
	void dfs(string &s, int start, vector<string> &ans, string &tmp) {
		if (start == s.size()) {
			ans.push_back(tmp);
			return;
		}
		int ts = tmp.size();
		for (int l = minLen; l <= min(maxLen, (int)s.size() - start); ++l) {
			string t = s.substr(start, l);
			if (dict.count(t)) {
				if (ts) tmp += ' ';
				tmp += t;
				dfs(s, start + l, ans, tmp);
				tmp.resize(ts);
			}
		}
	}

	vector<string> wordBreakMyDP(string s, vector<string>& wordDict){
		const int n = s.size();
		vector<bool> dp(n+1, false);
		vector<vector<pair<int, string>>> bk(n+1);
		dp[0] = true;
		for (int i = 1; i <= n; ++i){
			for (int j = i - 1; j >= 0; --j){
				if (dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()){
					dp[i] = true;
					bk[i].push_back({j, s.substr(j, i - j)});
				}
			}
		}
		// reconstruct solution
		if (dp[n]){
			rdfs(n, dp, bk);
		}
		return res;
	}
private:
	void rdfs(int index, vector<bool>& dp, vector<vector<pair<int, string>>>& bk){
		if (index == 0){
			string t;
			int c = ans.size();
			for (int i = c - 1; i > 0; --i){
				t = t + ans[i] + " ";
			}
			t = t + ans[0];
			res.push_back(t);
			return;
		}
		for (auto b : bk[index]){
			ans.push_back(b.second);
			rdfs(b.first, dp, bk);
			ans.pop_back();
		}
		return;
	}

public:
	vector<string> wordBreakMyDFS(string s, vector<string>& wordDict) {
		const int len = s.size();
		const int n = wordDict.size();
		maxdictlen = 0;
		for (auto word : wordDict){
			maxdictlen = max(maxdictlen, (int)word.size());
		}
		dfs(s, wordDict);
		return res;
	}
private:
	void dfs(string s, vector<string>& wordDict){
		if (s.empty()){
			string t;
			int c = ans.size();
			for (int i = 0; i < c - 1; ++i){
				t = t + ans[i] + " ";
			}
			t = t + ans[c - 1];
			res.push_back(t);
			return;
		}
		auto maxlen = min((int)s.size(), maxdictlen);
		for (int i = 1; i <= maxlen; ++i){
			if (find(wordDict.begin(), wordDict.end(), s.substr(0, i)) == wordDict.end()){
				continue;
			}
			ans.push_back(s.substr(0, i));
			dfs(s.substr(i), wordDict);
			ans.pop_back();
		}
	}
	vector<string> ans;
	vector<string> res;
	int maxdictlen;
};

int main(int argc, char *argv[]){
	Solution s;
	auto vs = s.wordBreak("catsanddog", vector<string>{"cat", "cats", "and", "sand", "dog"});
	for (auto v : vs) {
		cout << v << endl;
	}
	system("pause");
	return 0;
}