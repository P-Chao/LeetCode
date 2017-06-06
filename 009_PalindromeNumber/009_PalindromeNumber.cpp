#include <iostream>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x){
		if (x < 0){
			return false;
		}
		int y = 0, z = x;
		while (z) {
			y = 10 * y + z % 10;
			z /= 10;
		}
		return x == y;
	}

	bool isPalindromeMyAC(int x) {
		if (x < 0){
			return false;
		}
		if (x < 10){
			return true;
		}
		int n = 0;
		int y = x;
		while (y > 0){
			y = y / 10;
			n++;
		}
		while (n > 1){
			int s = x - (x /10) * 10;
			int t = pow(10, n-1);
			int m = x - s * t - s;
			if (m < 0){
				return false;
			}
			if (m / t != 0){
				return false;
			}
			n = n - 2;
			x = m / 10;
		}
		return true;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.isPalindrome(111332111) << endl;
	system("pause");
	return 0;
}