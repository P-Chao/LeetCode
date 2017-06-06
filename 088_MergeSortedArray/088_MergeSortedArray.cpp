#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (m == 0){
			nums1 = nums2;
			return;
		}
		if (n == 0){
			return;
		}
		nums1.resize(m + n);
		int i = m - 1, j = n - 1, k = m + n - 1;
		while (k >= 0)
		{
			if (i >= 0 && nums1[i] >= nums2[j]){
				nums1[k--] = nums1[i--];
			} else{
				nums1[k--] = nums2[j--];
			}
			if (j < 0){
				break;
			}
		}
		return;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	vector<int> nums1{ 1, 2, 3, 5 };
	vector<int> nums2{ 4, 6, 7, 9 };
	s.merge(nums1, nums1.size(), nums2, nums2.size());
	for (auto v : nums1){
		cout << v << ", ";
	}
	system("pause");
	return 0;
}