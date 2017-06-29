#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int integerReplacement(int n){
		if (n <= 1){
			return 0;
		} else if (n == INT_MAX){
			return 32;
		}
		if (n == 3){
			return 2;
		}
		if (n & 1){
			return (numTrailingOnes(n) > 1) ? (integerReplacement(n + 1) + 1) : (integerReplacement(n-1)+1);
		} else{
			return integerReplacement(n >> 1) + 1;
		}
	}
private:
	int numTrailingOnes(int num){
		int shift = 0;
		while ((num >> shift) & 1) {
			shift++;
		}
		return shift;
	}
public:
	int integerReplacementDPMEL(int n) {
		vector<int> dp(n+1, 0);
		for (int i = 2; i <= n; ++i){
			if ((i & 1) == 0){
				dp[i] = dp[i / 2] + 1;
			} else{
				if (i == INT_MAX){
					dp[i] == 2 + dp[i / 2 + 1];
				}
				dp[i] = min(dp[i-1], dp[(i+1)/2]+1) + 1;
			}
		}
		return dp[n];
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.integerReplacement(200000000) << endl;
	system("pause");
	return 0;
}