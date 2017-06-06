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
		int curMin = prices[0];
		int curMax = prices[0];
		int res = 0;
		for (int i = 1; i < n; ++i){
			int gain = prices[i] - prices[i - 1];
			if (gain > 0){
				res += gain;
			}
		}
		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.maxProfit(vector<int>{7, 1, 5, 3, 6, 4});
	system("pause");
	return 0;
}