#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		const int len = nums.size();
		if (len < 3){
			return 0;
		}
		int ret = 0;
		int minres = INT_MAX;
		sort(nums.begin(), nums.end());
		for (int k = 0; k < len - 2; ++k){
			if (k != 0 && nums[k] == nums[k - 1]){
				continue;
			}

			int i = k + 1;
			int j = len - 1;
			int t = target - nums[k];
			
			while (i < j){
				int res = t - nums[i] - nums[j];
				if (abs(res) < minres){
					ret = target - res;
					minres = abs(res);
				}
				if (res == 0){
					return target;
				} else if (res > 0){
					i++;
				} else{
					j--;
				}
			}
		}
		return ret;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.threeSumClosest(vector<int>{-1, 2, 1, -4}, 1) << endl;
	system("pause");
	return 0;
}