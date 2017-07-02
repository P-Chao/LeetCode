#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		const int n = nums.size();
		int l = 0, r = n - 1;
		while (l <= r) {
			if (target <= nums[l]){
				return l;
			}
			if (target == nums[r]){
				return r;
			}
			if (target > nums[r]){
				return r + 1;
			}
			int m = (l + r) / 2;
			if (target < nums[m]){
				r = m - 1;
			} else if(target > nums[m]){
				l = m + 1;
			} else{
				return m;
			}
		}
		return 0;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.searchInsert(vector<int>{1, 3}, 2) << endl;
	system("pause");
	return 0;
}