#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		const int n = nums.size();
		int fromBegin = 1, fromLast = 1;
		vector<int> res(n,1);
		
		for (int i = 0; i < n; ++i){
			res[i] *= fromBegin;
			fromBegin *= nums[i];
			res[n - 1 - i] *= fromLast;
			fromLast *= nums[n-1-i];
		}
		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	s.productExceptSelf(vector<int>{1, 2, 3, 4});
	system("pause");
	return 0;
}