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
			return m || n;
		}
		int distance = 0;
		int i = 0, j = 0;
		while (i < m && j < n){
			if (s[i++] != t[j++]){
				if (++distance > 1){
					return false;
				}
				if (m > n){
					j--;
				}
				if (m < n){
					i--;
				}
			}
		}
		if (i == m && j == n){
			return distance == 1;
		}
		return distance == 0;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.isOneEditDistance("a", "ac") << endl;
	system("pause");
	return 0;
}