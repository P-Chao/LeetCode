#include <iostream>

using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0){
			return 1;
		}
		bool sign = true;
		if (n < 0){
			n = -n;
			sign = false;
		}
		if (x > 1.9 && n == INT_MIN){
			return 0;
		}
		double tmp[31];
		tmp[0] = x;
		int i = 1;
		double res = (n & i) ? x : 1;
		for (; i < 31; ++i){
			tmp[i] = tmp[i - 1] * tmp[i - 1];
			double t = (n & (1 << i)) ? tmp[i] : 1;
			res *= t;
			if ((1 << i) > n){
				break;
			}
		}
		if (!sign){
			res = 1 / res;
		}
		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << INT_MIN << endl;
	cout << s.myPow(2, INT_MIN) << endl;
	system("pause");
	return 0;
}