#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution {
	using PQ = priority_queue < pair<int, int>, vector<pair<int, int>>,
		function<bool(const pair<int, int>&, const pair<int, int>&) >> ;
public:
	int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
		auto cmp1 = [](const pair<int, int>& lhs, const pair<int, int>& rhs) -> bool{
			return lhs.first > rhs.first;
		};
		auto cmp2 = [](const pair<int, int>& lhs, const pair<int, int>& rhs) -> bool{
			return lhs.second < rhs.second;
		};
		PQ pq1(cmp1), pq2(cmp2); // pq1是小顶堆，pq2是大顶堆

		const int n = Profits.size();
		for (int i = 0; i < n; ++i){
			pq1.push({Capital[i], Profits[i]});
		}

		int res = W;
		while (--k >= 0) {
			while (!pq1.empty() && pq1.top().first <= res){
				pq2.push(pq1.top());
				pq1.pop();
			}
			if (pq2.empty()){
				break;
			}
			res += pq2.top().second;
			pq2.pop();
		}
		return res;
	}

	int findMaximizedCapitalTEL(int k, int W, vector<int>& Profits, vector<int>& Capital) {
		const int n = Profits.size();
		k = (n > k) ? k : n;
		vector<bool> mask(n, true);
		int cap = W;
		for (int i = 0; i < k; ++i){
			int maxprof = 0;
			int index = -1;
			for (int j = 0; j < n; ++j){
				if (Capital[j] <= cap && maxprof < Profits[j] && mask[j]){
					maxprof = Profits[j];
					index = j;
				}
			}
			cap += maxprof;
			if (index != -1){
				mask[index] = false;
			}
		}
		return cap;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.findMaximizedCapital(10, 0, vector<int>{1, 2, 3}, vector<int>{0, 1, 2}) << endl;
	system("pause");
	return 0;
}