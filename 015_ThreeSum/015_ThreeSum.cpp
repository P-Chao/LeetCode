#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ret;
		const int len = nums.size();
		if (len < 3){
			return ret;
		}

		sort(nums.begin(), nums.end());
		for (int c = 0; c < len - 2; ++c){
			if (c != 0 && nums[c] == nums[c - 1]){
				continue;
			}
			int i = c + 1;
			int j = len - 1;
			const int target = -nums[c];
			while (i < j){
				int val = nums[i] + nums[j];
				if (val == target){
					ret.push_back(vector<int>{nums[c], nums[i], nums[j]});
					while (nums[i] == nums[i + 1] && i < j){
						i++;
					}
					while (nums[j] == nums[j - 1] && i < j){
						j--;
					}
					i++;
					j--;
				} else if (val < target){
					while (nums[i] == nums[i + 1] && i < j){
						i++;
					}
					i++;
				} else if (val > target){
					
					while (nums[j] == nums[j - 1] && i < j){
						j--;
					}
					j--;
				}
			}
		}
		return ret;

	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto r = s.threeSum(vector<int>{-4, -2, 1, -5, -4, -4, 4, -2, 0, 4, 0, -2, 3, 1, -5, 0});
	for (auto v : r){
		cout << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }" << endl;
	}
	system("pause");
	return 0;
}
