#include <iostream>

using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {
		int cnt = 0;
		while (n > 0){
			n = n / 5;
			cnt += n;
		}
		return cnt;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.trailingZeroes(25) << endl;
	system("pause");
	return 0;
}