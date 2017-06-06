#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		const int n = nums.size();
		if (n < 3){
			return n;
		}
		int cnt = 1, len = 1;
		int cur = nums[0];
		for (int i = 1; i < n; ++i){
			if (nums[i] == cur){
				if (cnt == 1){
					nums[len] = nums[i];
					len++;
					cnt++;
				}
			} else{
				cnt = 1;
				cur = nums[i];
				nums[len] = nums[i];
				len++;
			}
		}
		return len;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	vector<int> nums{ 1, 1, 1, 2, 2, 3 };
	int n = s.removeDuplicates(nums);
	for (int i = 0; i < n; ++i){
		cout << nums[i] << ", ";
	}
	system("pause");
	return 0;
}
