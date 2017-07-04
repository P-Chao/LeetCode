#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		vector<int> sorted(nums);
		sort(sorted.begin(), sorted.end());
		for (int i = nums.size() - 1, j = 0, k = i / 2 + 1; i >= 0; --i){
			nums[i] = sorted[i & 1 ? k++ : j++];
		}
		return;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	vector<int> nums{ 1, 2, 3, 4, 5, 2, 1, 1 };
	s.wiggleSort(nums);
	for (auto v : nums){
		cout << v << ", ";
	}
	system("pause");
	return 0;
}