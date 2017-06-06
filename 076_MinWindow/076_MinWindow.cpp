#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		vector<int> table(128, 0);
		int remaining = t.length();
		for (int i = 0; i<remaining; i++) table[t[i]]++;

		int fast = 0, slow = 0, start = 0, ans = INT_MAX;
		while (fast < s.length()) {
			char c = s[fast++];
			if (table[c]-- > 0){
				remaining--;
			}
			while (!remaining) { // remaining == 0时，符合要求			
				char ch = s[slow];
				if (table[ch]++ == 0){ // 遇到没有遇到的字符，从0向上，break
					remaining++; 
					if (ans > fast - slow) {
						ans = fast - slow;
						start = slow;
					}
				}
				slow++;
			}
		}

		return (ans == INT_MAX) ? "" : s.substr(start, ans);
	}

	string minWindowMy(string s, string t) {
		const int n = s.size();
		const int m = t.size();
		if (n == 0 || n == 0 || m > n){
			return string("");
		}
		unordered_map<char, int> table, window;
		for (int i = 0; i < m; ++i){
			table[t[i]]++;
		}

		int minlen = INT_MAX;
		pair<int, int> minpair = {0, -1};
		int l = 0, r = -1;
		while (r < n){	
			while (r < n){  // 扩张
				r++;
				if (!table[s[r]]){
					continue;
				}
				window[s[r]]++;
				if (window[s[r]] >= table[s[r]]){
					break;
				}
			}
			while (l <= r){ // 收缩
				if (!table[s[l]]){
					l++;
				} else if (window[s[l]] > table[s[l]]){
					window[s[l]]--;
					l++;
				} else{
					break;
				}
			}
			bool flag = true;
			for (auto tb : table){
				if (window[tb.first] < table[tb.first]){
					flag = false;
					break;
				}
			}
			if (flag){
				if (r - l + 1 < minlen){
					minlen = r - l + 1;
					minpair = { l, r };
				}
			}
		}
		return s.substr(minpair.first, minpair.second-minpair.first+1);
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.minWindow("aaflslflsldkalskaaa","aaa") << endl;
	system("pause");
	return 0;
}