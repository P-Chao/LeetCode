#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Solution: http://www.cnblogs.com/boring09/p/4252780.html

class Solution {
public:
	int maxSubArray(vector<int>& nums){
		const int n = nums.size();
		int sum = nums[n - 1];
		int maxsum = sum;

		for (int i = n - 2; i >= 0; --i){
			sum = max(nums[i], sum + nums[i]);
			maxsum = max(maxsum, sum);
		}
		return maxsum;
	}

	int maxSubArrayDP(vector<int>& nums){
		const int n = nums.size();
		if (n == 0){
			return 0;
		}
		int max_ending_here = nums[0];
		int max_so_far = nums[0];
		for (int i = 1; i < n; ++i){
			if (max_ending_here < 0){
				max_ending_here = nums[i];
			} else{
				max_ending_here += nums[i];
			}
			max_so_far = max(max_so_far, max_ending_here);
		}
		return max_so_far;
	}

	int maxSubArrayMyOld(vector<int>& nums) {
		const int n = nums.size();
		if (n == 0){
			return 0;
		}
		m_maxsum = INT_MIN;
		vector<vector<int>> table(n, vector<int>(n, INT_MIN));
		dp(0, n - 1, nums, table);
		return m_maxsum;
	}

private:
	int dp(int i, int j, vector<int>& nums, vector<vector<int>>& table){
		if (i == j){
			table[i][j] = nums[i];
		} else if (table[i][j] == INT_MIN){
			table[i][j] = max(dp(i + 1, j, nums, table) + nums[i], dp(i, j - 1, nums, table) + nums[j]);
		}
		if (table[i][j] > m_maxsum){
			m_maxsum = table[i][j];
		}
		return table[i][j];
	}
	int m_maxsum;
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.maxSubArray(vector<int>{-2, 1, -3, 4, -1, 2, 1, -5, 4}) << endl;
	system("pause");
	return 0;
}