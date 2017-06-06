#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int maxlen = 0;
		int start = 1; //start place order
		int table[256] = { 0 }; // save every char order, start from 1. 0 means not saved
		int strlen = s.length();
		for (int i = 0; i<strlen; i++){
			int* chpos = &table[s[i] + 128]; //char position
			if (*chpos != 0 && *chpos >= start){ // location before start are ignored
				start = *chpos + 1; //save old location, count from the next one
				*chpos = i + 1;
			} else{
				*chpos = i + 1;
				maxlen = max(maxlen, i - start + 2); //start-1 is the array number, add one more for it self exsiting
			}
		}
		return maxlen;
	}

	int lengthOfLongestSubstringMyDQ(string s) {
		const int n = s.size();
		if (n < 2){
			return n;
		}
		int length = 1;
		deque<char> dq;
		dq.push_back(s[0]);
		for (int i = 1; i < n; ++i){
			auto itl = dq.end();
			for (auto it = dq.begin(); it != dq.end(); it++){
				if (s[i] == *it){
					itl = it;
				}
			}
			if (itl != dq.end()){
				dq.erase(dq.begin(), itl+1);
			}
			dq.push_back(s[i]);
			if (dq.size() > length){
				length = dq.size();
			}
		}
		return length;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
	system("pause");
	return 0;
}
