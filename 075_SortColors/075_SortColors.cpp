#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		const int n = nums.size();
		int i = 0, j = 0, k = n-1;
		while (j <= k){
			switch (nums[j]){
			case 0:
				swap(nums[i++], nums[j++]);
				break;
			case 1:
				j++;
				break;
			case 2:
				swap(nums[j], nums[k--]);
				break;
			default:
				break;
			}
		}
		return;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	vector<int> v{ 0, 1, 2, 2, 1, 0 };
	s.sortColors(v);
	for (auto vv : v){
		cout << vv << ", ";
	}
	system("pause");
	return 0;
}