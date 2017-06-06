/*
Introduction to Algorithm
Peng Chao, 3,Apr
Line: 55
*/

#include <cstdio>
#include <iostream>

int merge(int *a, int p, int q, int r){
	
	int nl = q - p + 1;
	int nr = r - q;

	int *L = new int[nl+1];
	int *R = new int[nr+1];

	for (int ii = 0; ii < nl; ++ii){
		L[ii] = a[p+ii];
	}
	L[nl] = INT_MAX;

	for (int ii = 0; ii < nr; ++ii){
		R[ii] = a[q+ii+1];
	}
	R[nr] = INT_MAX;

	int i = 0, j = 0;

	for (int k = p; k <= r; ++k){
		if (L[i] <= R[j]){
			a[k] = L[i];
			i++;
		} else{
			a[k] = R[j];
			j++;
		}
	}

	delete[] L, R;
	return 0;
}


int mergeSort(int *a, int p, int r){
	if (p < r){
		int q = p + (r - p) / 2;
		mergeSort(a, p, q);
		mergeSort(a, q+1, r);
		merge(a, p, q, r);
	}

	return 0;
}
