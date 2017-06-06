#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		const int n = nums.size();
		int l = 0;
		int h = n - 1;
		while (l < h){
			int m = l + (h - l) / 2;
			if (nums[m] > nums[m + 1]){
				h = m;
			} else{
				l = m + 1;
			}
		}
		return l;
	}

	int findPeakElementL(vector<int>& nums) {
		const int n = nums.size();
		if (n >= 2){
			if (nums[0] > nums[1]){
				return 0;
			}
			if (nums[n - 1] > nums[n - 2]){
				return n - 1;
			}
		} else{
			return 0;
		}
		int diff = 0, curdiff = 0;
		for (int i = 1; i < n-1; ++i){
			if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]){
				return i;
			}
		}
		return 0;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.findPeakElement(vector<int>{1, 2, 3, 1}) << endl;
	system("pause");
	return 0;
}