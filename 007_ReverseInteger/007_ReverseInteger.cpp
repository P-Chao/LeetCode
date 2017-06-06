#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int reverse(int x) {
		int sign = 1;
		long long xx = x;
		if (x == 0){
			return x;
		} else if (x < 0){
			sign = -1;
			xx = -xx;
		}
		long long y = 0, z = xx;
		int t1 = INT_MAX / 10, t2 = INT_MAX % 10;
		while (z){
			y = 10 * y + z % 10;
			z /= 10;
			if (z > 0 && y >= t1){
				if (y == t1 && z <= t2){
					continue;
				}
				return 0;
			}
		}
		return sign == 1 ? y : -y;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.reverse(-2147483648) << endl;
	system("pause");
	return 0;
}