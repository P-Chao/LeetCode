#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		const int n = prices.size();
		if (n < 2 || k < 1){
			return 0;
		}
		if (k >= n){
			int profit = 0;
			for (int i = 1; i < n; ++i){
				int diff = diff = prices[i] - prices[i - 1];
				if (diff > 0){
					profit += diff;
				}
			}
			return profit;
		}
		/*vector<vector<int>> local(n, vector<int>(k+1, 0));
		vector<vector<int>> global(n, vector<int>(k+1, 0));
		for (int i = 1; i < n; ++i){
			for (int j = 1; j <= k; ++j){
				int diff = prices[i] - prices[i - 1];
				local[i][j] = max(global[i-1][j-1] + max(0, diff), local[i-1][j] + diff);
				global[i][j] = max(global[i-1][j], local[i][j]);
			}
		}*/

		vector<int> local(k+1, 0), global(k+1, 0);
		for (int i = 1; i < n; ++i){
			int diff = prices[i] - prices[i-1];
			for (int j = k; j >= 1; --j){  // 因为要保留i-1时j-1状态，所以从高到低
				local[j] = max(global[j-1] + max(0, diff), local[j] + diff);
				global[j] = max(global[j], local[j]);
			}
		}

		return global[k];
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.maxProfit(2, vector<int>{7, 1, 5, 3, 6, 4}); // 7
	system("pause");
	return 0;
}
