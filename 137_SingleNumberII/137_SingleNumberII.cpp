#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		if (nums.size() == 1)
			return nums[0];
		int test = 0;
		int a = 0;
		test = 3 >> 1;
		int ans = 0, count;
		for (int i = 1; i <= 32; i++){
			count = 0;
			for (int j = 0; j<nums.size(); j++){
				a = 1 << (i - 1);
				count += (nums[j] & a) >> (i - 1);
				test = (nums[j] & i) >> (i - 1);
			}
			if (count % 3 != 0){
				ans += 1 << (i - 1);
			}
		}

		return ans;
	}

	int singleNumberMy(vector<int>& nums) {
		int count[32] = { 0 };
		int result = 0;
		for (int i = 0; i < 32; ++i){
			for (auto num : nums){
				if (num & (1 << i)){
					count[i]++;
				}
			}
			if (count[i] % 3){
				result += (1 << i);
			}
		}
		return result;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.singleNumber(vector<int>{-2, -2, 1, 1, -3, 1, -3, -3, -4, -2}) << endl;
	system("pause");
	return 0;
}