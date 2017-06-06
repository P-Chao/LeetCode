/*
LeetCode 164
Peng Chao, 3,Apr
Line: 125
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		const int len = nums.size();
		if (len < 2){
			return 0;
		}
		
		vector<vector<int>> buckets(len+1);
		
		// can be optimized
		int n_max = nums[0], n_min = nums[0];
		for (auto num : nums){
			if (num > n_max){
				n_max = num;
			}
			else if(num < n_min){
				n_min = num;
			}
		}

		if (n_max == n_min){
			return 0;
		}

		// build buckets
		const float gap = (n_max - n_min) / (float)len;
		for (auto num : nums){
			int idx = (num - n_min) / gap;
			if (buckets[idx].empty()){
				buckets[idx].reserve(2);
				buckets[idx].push_back(num);
				buckets[idx].push_back(num);
			}
			else{
				if (num > buckets[idx][1]){
					buckets[idx][1] = num;
				} else if (num < buckets[idx][0]){
					buckets[idx][0] = num;
				}
			}
		}

		// search maxgap
		int maxgap = 0;
		int prev = 0;
		for (int i = 0; i < buckets.size(); ++i){
			if (buckets[i].empty()){
				continue;
			}
			maxgap = max(maxgap, buckets[i][0] - buckets[prev][1]);
			prev = i;
		}
		return maxgap;
	}

	int maximumGapO(vector<int>& nums) {
		// the straight-forward solution would be bucket sort
		// the maximum gap is garantteed to be in different buckets
		// O(N) in terms of both time and space

		int n = nums.size();
		if (n<2)
			return 0;
		int maxElement = nums[0];
		int minElement = nums[0];
		for (auto num : nums){
			if (num > maxElement){
				maxElement = num;
			}
			else if (num < minElement){
				minElement = num;
			}
		}
		//int minElement = *min_element(nums.begin(), nums.end()); 
		//int maxElement = *max_element(nums.begin(), nums.end()); 
		int length = maxElement - minElement;
		if (length <= 1)
			return length;
		vector<int> bucket_min(n, INT_MAX); // minimum value in each bucket
		vector<int> bucket_max(n, INT_MIN); // maximum value in each bucket
		int i, index;
		for (i = 0; i<n; i++)
		{
			index = 1.0*(nums[i] - minElement) / length*(n - 1);
			bucket_min[index] = min(bucket_min[index], nums[i]);
			bucket_max[index] = max(bucket_max[index], nums[i]);
		}

		int result = 0;
		int premax = bucket_max[0];
		for (i = 1; i<n; i++)
		{
			if (bucket_max[i] > INT_MIN) // there are elements in this bucket 
			{
				result = max(result, bucket_min[i] - premax);
				premax = bucket_max[i];
			}
		}

		return result;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	int a[] = {16, 1, 1, 1, 1, 2, 4, 7};
	vector<int> v(a, a + 8);
	cout << s.maximumGap(v);
	system("pause");
	return 0;
}