#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& v) {
		if (v.size() == 0)
			return 0;

		std::vector<int> tail(v.size(), 0); // 不是存储序列，二是存储对应长度的最小末尾
		int length = 1; // always points empty slot in tail

		tail[0] = v[0];
		for (size_t i = 1; i < v.size(); i++) {
			if (v[i] < tail[0])
				// new smallest value
				tail[0] = v[i];
			else if (v[i] > tail[length - 1])
				// v[i] extends largest subsequence
				tail[length++] = v[i];
			else
				// v[i] will become end candidate of an existing subsequence or
				// Throw away larger elements in all LIS, to make room for upcoming grater elements than v[i]
				// (and also, v[i] would have already appeared in one of LIS, identify the location and replace it)
				tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
		}

		return length;
	}
private:
	int CeilIndex(std::vector<int> &v, int l, int r, int key) {
		while (r - l > 1) {
			int m = l + (r - l) / 2;
			if (v[m] >= key)
				r = m;
			else
				l = m;
		}
		return r;
	}

public:
	int lengthOfLISMyDP(vector<int>& nums) {
		const int n = nums.size();
		if (n < 2){
			return n;
		}
		int maxdp = 1;
		vector<int> dp(n);
		dp[n - 1] = 1;
		for (int i = n - 2; i >= 0; --i){
			int maxlen = 1;
			for (int j = i + 1; j < n; ++j){
				if (nums[j] > nums[i]){
					maxlen = max(maxlen, dp[j] + 1);
				}
			}
			dp[i] = maxlen;
			maxdp = max(maxdp, maxlen);
		}
		return maxdp;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.lengthOfLIS(vector<int>{10, 9, 2, 5, 3, 7, 101, 18}) << endl;
	system("pause");
	return 0;
}