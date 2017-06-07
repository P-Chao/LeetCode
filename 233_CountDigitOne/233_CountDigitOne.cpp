#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int countDigitOne(int n) {
		int ones = 0;
		for (long m = 1; m <= n; m *= 10){
			long a = n / m, b = n % m;
			ones += (a + 8) / 10 * m;
			if (a % 10 == 1){
				ones += b + 1;
			}
		}
		return ones;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.countDigitOne(130) << endl;
	system("pause");
	return 0;
}