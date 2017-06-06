#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		const int n = s.size();
		if (n < 3 || numRows == 1){
			return s;
		}
		vector<string> ss(numRows);
		int r = 0;
		int m = numRows / 2;
		int isdown = 1; // will go to the mid
		for (int i = 0; i < n; ++i){
			ss[r] = ss[r] + s[i];
			r += isdown;	
			if (r >= numRows){
				r -= 2;
				isdown = -1;
			}	
			if (r < 0){
				r += 2;
				isdown = 1;
			}
		}
		string res;
		for (auto sr : ss){
			res += sr;
		}
		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.convert("ABC", 2) << endl;
	system("pause");
	return 0;
}