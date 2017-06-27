#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int count[26] = {0};
		for (auto c : ransomNote){
			count[c-'a']--;
		}
		for (auto c : magazine){
			count[c - 'a']++;
		}
		for (int i = 0; i < 26; ++i){
			if (count[i] < 0){
				return false;
			}
		}
		return true;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.canConstruct("aab", "aaabbb") << endl;
	system("pause");
	return 0;
}