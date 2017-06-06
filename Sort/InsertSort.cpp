/*
Introduction to Algorithm
Peng Chao, 3,Apr
Line: 44
*/

#include <iostream>
#include <cstdio>

int insertionSort(int* a, int len){
	// 核心是维持循环不变式
	if (len < 2)
		return 0;
	for (int j = 1; j < len; ++j){
		int i = j;
		while (i >= 0){
			if (a[i-1] > a[i]){
				int tmp = a[i-1];
				a[i-1] = a[i];
				a[i] = tmp;
			}
			i--;
		}
	}
	return 0;
}

int outputArray(int* a, int len){
	for (int i = 0; i < len; ++i)
		std::cout << a[i] << " ";
	std::cout << std::endl;
	return 0;
}

int heapSort(int *a, int length);
int mergeSort(int *a, int p, int r);
int quickSort(int *a, int p, int r);
int quickSortS(int *a, int p, int r);
int radixSort(int *a, int length);
int main(int argc, char *argv[]){
	int a[13] = {12, 36, 34, 9, 35, 127, 55, 91, 82, 55, 64, 1000, 2};
	insertionSort(a, 13);
	//mergeSort(a, 0, 12);
	//heapSort(a, 13);
	//quickSortS(a, 0, 12);
	//quickSort(a, 0, 12);
	//radixSort(a, 13);
	outputArray(a, 13);
	system("pause");
	return 0;
}
