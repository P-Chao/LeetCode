#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		const int n = nums.size();
		if (n == 0){
			return false;
		}
		int l = 0, r = n - 1;
		while (l <= r){
			int m = (l + r) / 2;
			if (nums[m] == target){
				return true;
			}
			if (nums[m] > nums[l]){
				if (nums[l] <= target && target <= nums[m]){
					r = m - 1;
				} else{
					l = m + 1;
				}
			} else if(nums[m] < nums[l]){
				if (target >= nums[l] || target <= nums[m]){
					r = m - 1;
				} else{
					l = m + 1;
				}
			} else{
				l++;
			}
		}
		return false;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.search(vector<int>{4, 5, 6, 7, 0, 1, 2}, 3) << endl;
	system("pause");
	return 0;
}