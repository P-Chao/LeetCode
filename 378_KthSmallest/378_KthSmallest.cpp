#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution // BST 39ms
{
public:
	int kthSmallest(vector<vector<int>>& matrix, int k)
	{
		int n = matrix.size();
		int le = matrix[0][0], ri = matrix[n - 1][n - 1];
		int mid = 0;
		while (le < ri)
		{
			mid = le + (ri - le) / 2;
			int num = 0;
			for (int i = 0; i < n; i++)
			{
				int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
				num += pos;
			}
			if (num < k)
			{
				le = mid + 1;
			}
			else
			{
				ri = mid;
			}
		}
		return le;
	}
};

class SolutionPQ{ // 52ms O(klog(n))
public:
	int kthSmallest(vector<vector<int>>& arr, int k){
		int n = arr.size(), m = arr[0].size();
		priority_queue < pair<int, pair<int, int>>,
			vector<pair<int, pair<int, int>>>,
			greater < pair<int, pair<int, int>> >> pq;

		for (int i = 0; i < n; ++i){
			pq.push({ arr[i][0], {i, 0} });
		}

		int x = k, ans;
		while (x--){
			const auto t = pq.top(); pq.pop();
			ans = t.first;
			const int i = t.second.first;
			const int j = t.second.second;
			if (j != m - 1){
				pq.push({ arr[i][j + 1], {i, j + 1} });
			}
		}

		return ans;
	}
};

class SolutionHS { // 400+ms O(n^2)
public:
	int heapify(vector<vector<int>>& matrix, vector<vector<bool>>& mask){
		const int n = matrix.size();
		int i = 0, j = 0;
		while (true){
			int vp = matrix[i][j];
			
			bool havelc = i < n - 1 && mask[i + 1][j];
			bool haverc = j < n - 1 && mask[i][j + 1];
			if ((!havelc) && (!haverc)){	// no lc no rc
				return 0;
			} else if(havelc && (!haverc)){ // only have lc
				if (matrix[i+1][j] < matrix[i][j]){
					swap(matrix[i+1][j], matrix[i][j]);
					i = i + 1;
				} else{
					return 0;
				}
			} else if((!havelc) && haverc){ // only have rc
				if (matrix[i][j + 1] < matrix[i][j]){
					swap(matrix[i][j+1], matrix[i][j]);
					j = j + 1;
				} else{
					return 0;
				}
			} else{			// choose largest
				int minst = matrix[i][j];
				pair<int, int> minid{ i, j };
				if (matrix[i][j + 1] < matrix[i][j]){
					minst = matrix[i][j + 1];
					minid = { i, j + 1 };
				} 
				if (matrix[i + 1][j] < minst){
					minst = matrix[i + 1][j];
					minid = { i + 1, j };
				}
				if (minid != pair<int, int>{i, j}){
					swap(matrix[i][j], matrix[minid.first][minid.second]);
					i = minid.first;
					j = minid.second;
				} else{
					return 0;
				}
			}
		}
	}

	int kthSmallest(vector<vector<int>>& matrix, int k) {
		const int n = matrix.size();
		if (n == 0 || k <= 0 || k > n*n){
			return 0;
		}
		
		vector<vector<bool>> mask(n, vector<bool>(n, true)); // true in avalible
		int i = n-1, j = n-1, res = 0, ii = 1;
		while (ii < k){
			ii++;
			swap(matrix[i][j], matrix[0][0]);
			mask[i][j] = false;
			heapify(matrix, mask);
			if (j == 0){
				j = n - 1;
				i -= 1;
				continue;
			}
			j -= 1;
		}

		return matrix[0][0];
	}
};

int main(int argc, char *argv[]){
	Solution s;
	vector<vector<int>> v{ { 1, 5, 9 }, { 10, 11, 13 }, { 12, 13, 15 } };
	for (int k = 1; k < 10; ++k)
		cout << s.kthSmallest(v, k) << endl;
	system("pause");
	return 0;
}
