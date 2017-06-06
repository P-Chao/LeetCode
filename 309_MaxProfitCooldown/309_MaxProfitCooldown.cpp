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
		int buy = INT_MIN, pre_buy = 0, sell = 0, pre_sell = 0;
		for (int price : prices){
			pre_buy = buy;
			buy = max(pre_sell - price, pre_buy);
			pre_sell = sell;
			sell = max(pre_buy + price, pre_sell);
		}
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.maxProfit(vector<int>{1, 2, 3, 0, 2}); // 3
	system("pause");
	return 0;
}
