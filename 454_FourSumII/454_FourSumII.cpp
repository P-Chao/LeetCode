#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int N = A.size(), N2 = N * N, *sumAB, *sumCD;
		if (N == 0)
			return 0;

		sumAB = (int *)malloc(sizeof(int) * N2);
		sumCD = (int *)malloc(sizeof(int) * N2);
		for (int i = 0, cn = 0; i < N; ++i)
			for (int j = 0; j < N; ++j) {
				sumAB[cn] = A[i] + B[j];
				sumCD[cn++] = C[i] + D[j];
			}
		sort(sumAB, sumAB + N2);
		sort(sumCD, sumCD + N2);

		int ans = 0;
		int front = 0, back = N2 - 1;
		while (front < N2 && back >= 0) { // Ë«Êý×éË«Ö¸Õë
			if (sumAB[front] + sumCD[back] > 0)
				back--;
			else if (sumAB[front] + sumCD[back] < 0)
				front++;
			else {
				int cnAB = 1, cnCD = 1;
				while (++front < N2 && sumAB[front] == sumAB[front - 1])  cnAB++;
				while (--back >= 0 && sumCD[back] == sumCD[back + 1])     cnCD++;
				ans += cnAB * cnCD;
			}
		}
		return ans;
	}

	int fourSumCountHash(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		const int a = A.size(), b = B.size(), c = C.size(), d = D.size();
		unordered_map<long long, int> mp1, mp2;
		for (int i = 0; i < a; ++i){
			for (int j = 0; j < b; ++j){
				mp1[A[i] + B[j]]++;
			}
		}
		for (int i = 0; i < c; ++i){
			for (int j = 0; j < d; ++j){
				mp2[C[i] + D[j]]++;
			}
		}
		int count = 0;
		for (auto m : mp1){
			count += (m.second * mp2[-m.first]);
		}
		return count;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.fourSumCount(vector<int>{1, 2}, vector<int>{-2, -1}, vector<int>{-1, 2}, vector<int>{0, 2}) << endl;
	system("pause");
	return 0;
}