#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int bit = 0;
		while (m!=n) {
			m = m >> 1;
			n = n >> 1;
			bit++;
		}
		return n << bit;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.rangeBitwiseAnd(5, 7) << endl;
	system("pause");
	return 0;
}