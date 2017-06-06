#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1 == s2){
			return true;
		}
		const int len = s1.size();
		int count[26] = { 0 };
		for (int i = 0; i < len; ++i){
			count[s1[i] - 'a']++;
			count[s2[i] - 'a']--;
		}

		for (int i = 0; i < 26; ++i){
			if (count[i]){
				return false;
			}
		}

		for (int i = 1; i < len; ++i){
			if (isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i))){
				return true;
			}
			if (isScramble(s1.substr(0,i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0, len-i))){
				return true;
			}
		}
		return false;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.isScramble("ab", "ba") << endl;
	system("pause");
	return 0;
}
