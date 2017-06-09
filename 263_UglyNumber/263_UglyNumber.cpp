#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isUgly(int num) {
		int prime[3] = { 2, 3, 5 };
		int i = 0;
		while (num > 1 && i < 3){
			if (num % prime[i] == 0){
				num = num / prime[i];
				continue;
			}
			++i;
		}
		return num == 1;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.isUgly(0) << endl;
	system("pause");
	return 0;
}