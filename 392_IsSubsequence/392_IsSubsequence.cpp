#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isSubsequence(string s, string t) {
		const int n = s.size();
		const int m = t.size();
		if (n == 0){
			return true;
		}
		if (m == 0){
			return false;
		}
		int i = 0, j = -1;
		while (++j < m){
			if (t[j] == s[i]){
				if (i++ == n - 1){
					return true;
				}
			}
		}
		return false;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.isSubsequence("abc", "ahbgdc") << endl;
	system("pause");
	return 0;
}