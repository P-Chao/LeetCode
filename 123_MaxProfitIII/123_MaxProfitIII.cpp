#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		const int n = prices.size();
		if (n < 2){
			return 0;
		}
		vector<int> back(n, 0), forw(n, 0);

		int curMin = prices[0];
		for (int i = 1; i < n; ++i){	
			if (prices[i] < curMin){
				curMin = prices[i];
			}
			forw[i] = max(forw[i-1], prices[i] - curMin);
		}

		int curMax = prices[n-1];
		for (int i = n - 2; i >= 0; --i){
			if (curMax < prices[i]){
				curMax = prices[i];
			}
			back[i] = max(back[i+1], curMax - prices[i]);
		}

		int profit = 0;
		for (int i = 0; i < n; ++i){
			profit = max(profit, forw[i] + back[i]);
		}

		return profit;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.maxProfit(vector<int>{7, 1, 5, 3, 6, 4});
	system("pause");
	return 0;
}