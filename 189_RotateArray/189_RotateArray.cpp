#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		const int n = nums.size();
		if (k > n){
			k = k % n;
		}
		k = n - k;
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());
		reverse(nums.begin(), nums.end());
		return;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	vector<int> nums{ 1, 2, 3, 5, 7, 8 };
	s.rotate(nums, 2);
	system("pause");
	return 0;
}
