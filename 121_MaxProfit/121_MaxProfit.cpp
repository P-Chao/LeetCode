#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		const int n = prices.size();
		if (n == 0){
			return 0;
		}

		int curMin = prices[0];
		int ret = 0;
		for (int i = 1; i < n; ++i){
			curMin = min(curMin, prices[i]);
			ret = max(ret, prices[i]-curMin);
		}
		return ret;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.maxProfit(vector<int>{7, 1, 5, 3, 6, 4});
	system("pause");
	return 0;
}