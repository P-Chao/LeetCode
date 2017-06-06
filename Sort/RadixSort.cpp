#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int radixSort(int *a, int len){
	int base = 10;
	int maxvalue = a[0];
	for (int i = 1; i < len; ++i){
		if (a[i] > maxvalue){
			maxvalue = a[i];
		}
	}
	vector<vector<int>> buckets(base);
	for (int i = 1; i <= maxvalue; i = i*base){
		for (int j = 0; j < len; j++){
			buckets[(a[j] / i) % base].push_back(a[j]);
		}
		int k = 0;
		for (int j = 0; j < base; j++){
			for (auto num : buckets[j]){
				a[k++] = num;
			}
			buckets[j].clear();
		}
	}
	return 0;
}