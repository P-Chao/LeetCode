#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool isOneEditDistance(string s, string t) {
		const int m = s.size();
		const int n = t.size();
		if (abs(m - n) > 1){
			return false;
		}
		if (m == 0 || n == 0){
			return true;
		}
		int distance = 0;
		if (abs(m - n) == 1){
			int i = 0, j = 0, ii = n-1, jj = m-1;
			while (s[i] == t[j]) {
				++i;
				++j;
			}
			while (s[ii] == t[jj] && ii > i && jj > j){
				--ii;
				--jj;
			}





		}
		if (m == n){
			for (int i = 0; i < 1; ++i){
				if (s[i] != t[i]){
					++distance;
					if (distance > 1){
						return false;
					}
				}
			}

		}
		return distance == 1;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.isOneEditDistance("abcd", "bcd") << endl;
}