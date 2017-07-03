#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		const int n = nums.size();
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