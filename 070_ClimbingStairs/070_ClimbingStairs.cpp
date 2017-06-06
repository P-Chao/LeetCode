#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		int cur = 1, pprev = 0, prev = 1;
		for (int i = 1; i <= n; ++i){
			cur = prev + pprev;
			pprev = prev;
			prev = cur;
		}
		return cur;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.climbStairs(0) << endl;
	system("pause");
	return 0;
}