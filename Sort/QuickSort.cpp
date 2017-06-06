/*
Introduction to Algorithm
Peng Chao, 3,Apr
Line: 68
*/

#include <cstdio>
#include <vector>

using namespace std;

int partition(int *a, int p, int r){
	int x = a[r];
	int i = p - 1, j = p;
	for (int j = p; j < r; ++j){
		if (a[j] <= x){
			++i;
			int tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
		}
	}
	++i;
	int tmp = a[i];
	a[i] = a[r];
	a[r] = tmp;
	return i;
}

int quickSort(int *a, int p, int r){
	if (p < r){
		int q = partition(a, p, r);
		quickSort(a, p, q-1);
		quickSort(a, q+1, r);
	}
	return 0;
}

vector<int> partitionS(int *a, int p, int r){
	vector<int> q;
	int x = a[r];
	int i = p, j = p, k = r;

	while (j <= k){
		if (a[j] > a[i]){
			swap(a[j], a[k]);
			k--;
		} else if(a[j] < a[i]){
			swap(a[j], a[i]);
			i++;
			j++;
		} else{
			j++;
		}
	}
	q.push_back(i-1);
	q.push_back(j);
	return q;
}

int quickSortS(int *a, int p, int r){
	if (p < r){
		vector<int> q = partitionS(a, p, r);
		quickSortS(a, p, q[0]);
		quickSortS(a, q[1], r);
	}
}
