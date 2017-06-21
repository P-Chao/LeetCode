#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int slow = 0, fast = 0, finder = 0;
		while (true){
			slow = nums[slow];
			fast = nums[nums[fast]];
			if (slow == fast) break;
		}
		while (true){
			slow = nums[slow];
			finder = nums[finder];
			if (slow == finder) return finder;
		}
		return finder;
	}

	int findDuplicateMy(vector<int>& nums) {
		const int n = nums.size();
		if (n < 2){
			return 0;
		}
		sort(nums.begin(), nums.end());
		for (int i = 1; i < n; ++i){
			if (nums[i] == nums[i - 1]){
				return nums[i];
			}
		}
		return 0;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.findDuplicate(vector<int>{2, 2, 2, 2, 2}) << endl;
	system("pause");
	return 0;
}
