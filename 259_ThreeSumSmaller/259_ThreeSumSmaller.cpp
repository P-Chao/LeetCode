#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int threeSumSmaller(vector<int>& nums, int target) {
		const int n = nums.size();
		sort(nums.begin(), nums.end());
		int cnt = 0;
		for (int i = 0; i < n - 2; ++i){
			int j = i + 1, k = n - 1, tar = target - nums[i];
			while (j < k) {
				int t = nums[j] + nums[k];
				if (t < tar){
					cnt += k - (j++);
					j++;
				} else {
					k--;
				} 
			}
		}
		return cnt;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.threeSumSmaller(vector<int>{-2, 1, 1}, 1) << endl;
	system("pause");
	return 0;
}