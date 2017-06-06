#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		const int n = nums.size();
		int minid = 0;
		for (int i = n - 2; i >= 0; --i){
			int curmin = INT_MAX;
			for (int j = i + 1; j < n; ++j){
				int tmp = nums[j] - nums[i];
				if (tmp > 0){
					curmin = min(curmin, tmp);
					minid = j;
				}
			}
			if (curmin < INT_MAX){
				swap(nums[i], nums[minid]);
				minid = i + 1;
				break;
			}
		}
		sort(nums.begin() + minid, nums.end());
		return;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	vector<int> vec{ 23, 16, 1, 20 };
	s.nextPermutation(vec);
	for (auto v : vec){
		cout << v << ", ";
	}
	system("pause");
	return 0;
}
