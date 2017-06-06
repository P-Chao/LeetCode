#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		const int n = nums.size();
		if (n == 0){
			return 0;
		}
		int curMin = nums[n - 1];
		int curMax = nums[n - 1];
		int maxpro = nums[n - 1];
		for (int i = n-2; i >= 0; --i){
			int n1 = nums[i] * curMin;
			int n2 = nums[i] * curMax;
			if (n1 > n2){
				swap(n1, n2);
			}
			curMin = min(nums[i], n1);
			curMax = max(nums[i], n2);
			if (curMax > maxpro){
				maxpro = curMax;
			}
		}
		return maxpro;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.maxProduct(vector<int>{2, 3, -2, 4}) << endl;
	system("pause");
	return 0;
}
