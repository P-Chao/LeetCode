#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		long long a = dividend;
		long long b = divisor;
		int sign = 1;
		if (a == 0){
			return 0;
		}
		else if (a < 0){
			a = -a;
			sign = -sign;
		}
		if (b == 0){
			return INT_MAX;
		} else if (b < 0){
			b = -b;
			sign = -sign;
		}
		if (a < b){
			return 0;
		}

		long long val[33], times[33];
		val[0] = b; 
		times[0] = 1;
		int i = 0;
		for (i = 1; i < 33; ++i){
			val[i] = (val[i-1] << 1);
			times[i] = (times[i-1] << 1);
			if (val[i] > a){
				break;
			}
		}
		long long res = 0;
		--i;
		for (; i >= 0; --i){
			if (a >= val[i]){
				a -= val[i];
				res += times[i];
			}
		}
		if (sign == 1 && res >= INT_MAX){
			return INT_MAX;
		}
		if (sign == -1){
			res = -res;
			if (res < INT_MIN){
				return INT_MIN;
			}
		}

		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.divide(-2147483648, -1) << endl;
	system("pause");
	return 0;
}