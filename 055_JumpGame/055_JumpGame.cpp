#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool canJump(vector<int> nums) {
		const int n = nums.size();
		int i = 0;
		for (int reach = 0; i < n && i <= reach; ++i)
			reach = max(i + nums[i], reach);
		return i == n;
	}

	bool canJumpGreey(vector<int>& nums) {
		const int n = nums.size();
		if (n == 0){
			return false;
		}
		int maxjump = -1;
		for (int i = 0; i < n; ++i){
			if (nums[i] > maxjump){
				maxjump = nums[i];
			}
			if (maxjump >= n-i-1){ // last element can achieve
				return true;
			}
			if (maxjump == 0){
				return false;
			}
			maxjump--;
		}
		return false;
	}

	bool canJumpGreeyMy(vector<int>& nums) {
		const int n = nums.size();
		if (n == 0){
			return true;
		}
		if (nums[0] == 0){
			return false;
		}
		if (n == 1){
			return true;
		}
		int cur = 0;
		while (cur < n - 1){
			if (nums[cur] == 0){
				return false;
			}
			int ed = cur + nums[cur];
			if (ed >= n - 1){
				return true;
			}
			int mx = cur;
			int mi = 0;
			for (int i = cur + 1; i <= ed; ++i){
				if (i + nums[i] > mx){
					mx = i + nums[i];
					mi = i;
				}
				cur = mi;
				
			}
		}
		return true;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.canJump(vector<int>{3, 0, 8, 2, 0, 0, 1}) << endl;
	system("pause");
	return 0;
}