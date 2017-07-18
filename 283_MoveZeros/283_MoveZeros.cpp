#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		const int n = nums.size();
		for (int j = 0, i = 0; j < n; ++j){
			if (nums[j]){
				swap(nums[j], nums[i++]);
			}
		}
		return;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	vector<int> nums{0, 1, 0, 3, 12};
	s.moveZeroes(nums);
	for (auto v : nums){
		cout << v << ", ";
	}
	system("pause");
	return 0;
}