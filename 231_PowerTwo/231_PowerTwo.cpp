#include <iostream>

using namespace std;

class Solution {
public:
	bool isPowerOfTwo(int n) {
		while (n > 0){
			if ((n & 0x01)){
				if (n == 1){
					return true;
				} else{
					return false;
				}
			}
			n = n >> 1;
		}
		return false;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.isPowerOfTwo(8) << endl;
	system("pause");
	return 0;
}