#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		int count[26] = { 0 };
		if (s.size() != t.size()){
			return false;
		}
		for (auto c : t){
			count[c - 'a']++;
		}
		for (auto c : s){
			count[c - 'a']--;
		}
		for (int i = 0; i < 26; ++i){
			if (count[i] != 0){
				return false;
			}
		}
		return true;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.isAnagram("anagram", "nagaram") << endl;
	system("pause");
	return 0;
}