/*
Introduction to Algorithm
Peng Chao, 3,Apr
Line: 63
*/

#include <cstdio>
#include <iostream>

inline int left(int i){
	return 2 * i + 1;
}

inline int right(int i){
	return 2 * i + 2;
}

inline int parent(int i){
	return (i - 1) / 2;
}

int maxHeapify(int *a, int i, int heapsize){
	int maxv = a[i];
	int maxi = i;
	if (left(i) < heapsize){
		if (a[left(i)] > maxv){
			maxv = a[left(i)];
			maxi = left(i);
		}
	}
	if (right(i) < heapsize){
		if (a[right(i)] > maxv){
			//maxv = a[right(i)];
			maxi = right(i);
		}
	}
	if (maxi != i){
		int tmp = a[i];
		a[i] = a[maxi];
		a[maxi] = tmp;
		maxHeapify(a, maxi, heapsize);
	}
	return 0;
}

int buildMaxHeap(int *a, int length){
	for (int i = length/2-1; i >= 0; i--){
		maxHeapify(a, i, length);
	}
	return 0;
}

int heapSort(int *a, int length){
	buildMaxHeap(a, length);
	for (int i = length - 1; i > 0; --i){
		int tmp = a[i];
		a[i] = a[0];
		a[0] = tmp;
		maxHeapify(a, 0, length);
	}
	return 0;
}
