#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int numSquares(int n) {
		vector<int> nums(n+1, INT_MAX);
		for (int i = 0; i*i <= n; ++i){
			nums[i*i] = 1;
		}
		for (int a = 0; a <= n; ++a){
			for (int b = 0; a+b*b <= n; ++b){
				nums[a+b*b] = min(nums[a+b*b], nums[a] + 1);
			}
		}
		return nums[n];
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.numSquares(12) << endl;
	system("pause");
	return 0;
}