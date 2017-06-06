#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> res;
		const int n = nums.size();
		if (n < 4){
			return{};
		}
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n; ++i){
			if (i && nums[i] == nums[i - 1]){
				continue;
			}
			int targ = target - nums[i];
			for (int j = i + 1; j < n; ++j){
				if (j != i + 1 && nums[j] == nums[j - 1]){
					continue;
				}
				int tar = targ - nums[j];
				int l = j + 1, r = n - 1;
				while (l < r){
					int sums = nums[l] + nums[r];
					if (sums < tar){
						l++;
						while (l < r && nums[l] == nums[l - 1]){
							l++;
						}
					} else if (sums > tar){
						r--;
						while (l < r && nums[r] == nums[r + 1]){
							r--;
						}
					} else{
						res.push_back({nums[i], nums[j], nums[l], nums[r]});
						r--;
						while (l < r && nums[r] == nums[r + 1]){
							r--;
						}
						l++;
						while (l < r && nums[l] == nums[l - 1]){
							l++;
						}
					}
				}
			}
		}
		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto res = s.fourSum(vector<int>{1, 0, -1, 0, -2, 2}, 0);
	for (auto vv : res){
		for (auto v : vv){
			cout << v << ", ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}