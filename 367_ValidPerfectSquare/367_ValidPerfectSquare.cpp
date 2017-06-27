#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isPerfectSquare(int num) {
		if (num <= 0){
			return false;
		} else if (num == 1){
			return true;
		}
		const int a = num / 2;
		for (int i = 1; i <= a; ++i){
			if (i*i > num){
				return false;
			}
			if (i*i == num){
				return true;
			}
		}
		return false;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.isPerfectSquare(16) << endl;
	system("pause");
	return 0;
}
