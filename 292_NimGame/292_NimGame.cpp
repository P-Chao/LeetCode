#include <iostream>

using namespace std;

class Solution {
public:
	bool canWinNim(int n) {
		return (n & 3);
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.canWinNim(3) << endl;
	system("pause");
	return 0;
}