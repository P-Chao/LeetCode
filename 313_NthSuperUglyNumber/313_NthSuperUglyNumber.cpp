#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
	int nthSuperUglyNumberDP2(int n, vector<int>& primes) {
		vector<int> idx(primes.size(), 0);							// current index for primes[i] in dp
		vector<int> next(primes.size(), 0);							// next available primes[i] * dp[idx[i]]
		vector<int> dp(n, 0); dp[0] = 1;							// dp for answer

		for (int i = 0; i < primes.size(); i++) {
			next[i] = primes[i];                                    // initialize the values
		}

		for (int i = 1; i < n; i++) {
			dp[i] = INT_MAX;
			for (int j = 0; j < primes.size(); j++) {
				dp[i] = (std::min)(dp[i], next[j]);                 // find min in next for dp[i] 
			}
			for (int j = 0; j < primes.size(); j++) {
				if (dp[i] == next[j]) {
					next[j] = primes[j] * dp[++idx[j]];             // update idx and next
				}
			}
		}
		return dp[n - 1];
	}

	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> index(primes.size(), 0);
		vector<int> dp(n);
		
		const int len = primes.size();
		int cur = 1;
		dp[0] = 1;
		while (cur < n){	// 正在生成第cur个丑数
			int mindp = INT_MAX;
			int minid = 0;
			for (int i = 0; i < len; ++i){
				if (primes[i] * dp[index[i]] < mindp){
					mindp = primes[i] * dp[index[i]];
					minid = i;
				}
			}
			index[minid]++; // 更新可能的最小值，该值当前已经使用过
			if (mindp != dp[cur - 1]){// 注意相等情况下，不存储当前值
				dp[cur] = mindp;
				cur++;
			}
		}
		return dp[n - 1];
	}
};

int main(int argc, char *argv[]){
	Solution s;
	vector<int> primes{2, 3, 5};
	for (int i = 1; i < 14; ++i){
		cout << s.nthSuperUglyNumber(i, primes) << ", ";
	}
	system("pause");
	return 0;
}
