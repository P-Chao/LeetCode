#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		const int n = nums.size();
		if (n < 2){
			return n;
		}
		int res = 1, prev = nums[0], i = 1;
		while (i < n && nums[i] == nums[i-1]){
			++i;
		}
		if (i == n){
			return res;
		}
		bool inc = (nums[i] > nums[i-1]);
		++i; ++res;
		for (; i < n; ++i){
			if (nums[i] > nums[i - 1]){
				if (!inc){
					res++;
					inc = true;
				}
			} else if (nums[i] < nums[i - 1]){
				if (inc){
					res++;
					inc = false;
				}
			}
		}
		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.wiggleMaxLength(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}) << endl;
	system("pause");
	return 0;
}
