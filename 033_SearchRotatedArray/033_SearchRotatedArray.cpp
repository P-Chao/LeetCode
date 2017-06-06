#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target){
		const int n = nums.size();
		int l = 0, r = n - 1;
		while (l <= r){
			int m = (l + r) / 2;
			if (nums[m] == target){
				return m;
			}
			if (nums[m] >= nums[l]){
				if (nums[l] <= target && target <= nums[m]){
					r = m - 1;
				} else{
					l = m + 1;
				}
			} else{
				if (target >= nums[l] || target <= nums[m]){
					r = m - 1;
				} else{
					l = m + 1;
				}
			}
		}
		return -1;
	}

	int searchL(vector<int>& nums, int target) {
		const int n = nums.size();
		for (int i = 0; i < n; ++i){
			if (nums[i] == target){
				return i;
			}
		}
		return -1;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.search(vector<int>{1, 2, 3, 4, 5, 6, 7}, 2) << endl;
	system("pause");
	return 0;
}
