
#include <iostream>
#include <cstdio>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
	int nthUglyNumber3mm(int n) { //3mm
		static vector<int> ugly{ 0, 1 };
		static int m1 = 1, m2 = 1, m3 = 1;
		if (n < ugly.size()) {
			return ugly[n];
		}
		int next = 0;
		while (n >= ugly.size()) {
			next = min(ugly[m1] * 2, min(ugly[m2] * 3, ugly[m3] * 5));
			ugly.push_back(next);
			if (ugly[m1] * 2 == next) {
				++m1;
			}
			if (ugly[m2] * 3 == next) {
				++m2;
			}
			if (ugly[m3] * 5 == next) {
				++m3;
			}
		}
		return ugly[n];
	}

	int nthUglyNumber(int n){
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		long long ans = 1;
		for (int i = 1; i < n; ++i){
			pq.push(2 * ans);
			pq.push(3 * ans);
			pq.push(5 * ans);
			ans = pq.top();
			while (pq.top() <= ans){
				pq.pop();
			}
		}
		return ans;
	}

	int nthUglyNumberDP(int n) { // 6ms
		int *un = new int[n];
		int next[3] = { 2, 3, 5 };
		int id[3] = { 0, 0, 0 };
		const int p[3] = { 2, 3, 5 };
		un[0] = 1;
		for (int i = 1; i < n; ++i){
			int min = INT_MAX;
			int mid = 0;
			for (int j = 0; j < 3; ++j){
				if (next[j] < min){
					min = next[j];
				}
			}
			un[i] = min;
			for (int j = 0; j < 3; ++j){
				if (next[j] == min){
					next[j] = p[j]*un[++id[j]];  //important
				}
			}
		}

		int ans = un[n - 1];
		delete[] un;
		return ans;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.nthUglyNumber(1404);
	for (int i = 1; i < 10; ++i){
		//cout << s.nthUglyNumber(i) << ", ";
	}
	system("pause");

	return 0;
}

