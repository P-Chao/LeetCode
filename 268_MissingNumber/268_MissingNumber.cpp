#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int i = 0;
		int res = 0;
		while (i < nums.size()) {
			res ^= nums[i];
			res ^= i;
			i++;
		}
		return res^i;
	}

	int missingNumberMy(vector<int>& nums) {
		const int n = nums.size();
		long long sum = 0;
		for (auto& num : nums){
			sum += num;
		}
		return ((1 + n) * (long long)n) / 2 - sum;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.missingNumber(vector<int>{0, 1, 3}) << endl;
	system("pause");
	return 0;
}