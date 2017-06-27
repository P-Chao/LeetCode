#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		const int n = s.size();
		int count[26] = {0};
		for (auto c : s){
			count[c - 'a']++;
		}
		for (int i = 0; i < n; ++i){
			if (count[s[i]-'a'] == 1){
				return i;
			}
		}
		return -1;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.firstUniqChar("leetcode") << endl;
	system("pause");
	return 0;
}