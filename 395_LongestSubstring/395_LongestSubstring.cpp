#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int longestSubstring(string s, int k) { // 用分治法，而不是滑动窗口
		int total[26] = { 0 };
		for (int i = 0; i<s.size(); i++){ // 统计词频
			total[s[i] - 'a']++;
		}
		int i = 0;
		while (i < s.size() && total[s[i] - 'a'] >= k){ // 从0开始扫描连续满足条件的序列
			i++;
		}
		if (i == s.size()) { // 说明整个序列都满足
			return i;
		}
		int j = i;
		while (j < s.size() && total[s[j] - 'a'] < k){ // 从中断位置开始扫描不满足的连续序列，找到分治端点
			j++;
		}
		return max(longestSubstring(s.substr(0, i), k), longestSubstring(s.substr(j), k)); // 分而治之
	}

	int longestSubstringDirect(string s, int k) {
		const int n = s.size();
		int i = 0, res = 0;
		while (i + k <= n) {
			int m[26] = { 0 }, mask = 0, max_idx = i;
			for (int j = i; j < n; ++j){
				int t = s[j] - 'a';
				++m[t];
				if (m[t] < k){
					mask |= (1 << t);
				} else{
					mask &= (~(1 << t));
				}
				if (mask == 0){
					res = max(res, j - i + 1);
					max_idx = j;
				}
			}
			i = max_idx + 1;
		}
		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.longestSubstring("ababbc", 2) << endl;
	system("pause");
	return 0;
}