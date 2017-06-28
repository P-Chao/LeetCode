#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	char findTheDifference(string s, string t) {
		int count[26] = { 0 };
		for (auto c : s){
			count[c - 'a']--;
		}
		for (auto c : t){
			count[c - 'a']++;
		}
		for (int i = 0; i < 26; ++i){
			if (count[i] > 0){
				return 'a' + i;
			}
		}
		return 0;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.findTheDifference("abcd", "abcde") << endl;
	system("pause");
	return 0;
}