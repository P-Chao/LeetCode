#include <iostream>

using namespace std;

class Solution {
public:
	int getSum(int a, int b) {
		int nr = a ^ b;
		int ad = ((a & b) << 1);
		if (nr & ad){
			return getSum(nr, ad);
		}
		return (nr | ad);
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.getSum(0, 1) << endl;
	system("pause");
	return 0;
}