#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		const int n = coins.size();
		if (amount == 0){
			return 0;
		}
		if (amount < 0 || n == 0){
			return -1;
		}
		vector<int> dp(amount+1, INT_MAX);

		for (auto coin : coins){
			if (coin <= amount){
				dp[coin] = 1;
			}
		}

		for (int a = 1; a <= amount; ++a){
			for (int b = 0; b < n; ++b){
				if (coins[b] > amount || dp[a] == INT_MAX){
					continue;
				}
				int at = a + coins[b];
				if (at <= amount){
					dp[at] = min(dp[at], dp[a] + 1);
				}
			}
		}
		if (dp[amount] == INT_MAX){
			return -1;
		}
		return dp[amount];
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.coinChange(vector<int>{1}, 2) << endl;
	system("pause");
	return 0;
}