#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isPowerOfThree(int n) {
		while (n > 0){
			if (n < 3){
				if (n == 1){
					return true;
				} else{
					return false;
				}
			}
			int tmp = n;
			n = n / 3;
			if (tmp - 3 * n){
				return false;
			}
		}
		return false;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.isPowerOfThree(10) << endl;
	system("pause");
	return 0;
}