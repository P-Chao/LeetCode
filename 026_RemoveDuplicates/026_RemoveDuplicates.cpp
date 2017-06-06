#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		const int n = nums.size();
		if (0 == n) return 0;
		int p = 1;
		for (int i = 1; i<n; i++){
			if (nums[i - 1] != nums[i])
				nums[p++] = nums[i];
		}
		return p;
	}
};