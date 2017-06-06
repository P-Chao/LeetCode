#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		if (x <= 1)
			return x;
		int low = 1, high = x, mid = low + (high - low) / 2;
		while (low <= high) {
			if (mid <= x / mid && (mid + 1) > x / (mid + 1))
				return mid;
			else if (mid < x / mid)
				low = mid + 1;
			else
				high = mid - 1;
			mid = low + (high - low) / 2;
		}
		return mid;
	}

	int mySqrtMy(int x) {
		if (x <= 0){
			return 0;
		} else if (x < 4){
			return 1;
		} else if (x < 9){
			return 2;
		}
		double l = 1, r = x;
		double mid = (l + r) / 2;

		while (l < r){
			mid = (l + r) / 2;
			double tmp = mid * mid;
			if (tmp > x){
				r = mid;
			} else if (tmp < x){
				l = mid;
			} if (abs(tmp - x) < 1e-1){
				break;
			}
		}
		return (int)(mid);
	}
};
int main(int argc, char *argv[]){
	Solution s;
	cout << s.mySqrt(4) << endl;
	system("pause");
	return 0;
}