#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		const int n = nums.size();
		unordered_map<int, int> table;
		for (int i = 0; i < n; ++i){
			if (table.find(nums[i]) == table.end()){
				table[nums[i]] = i;
			} else{
				if (i - table[nums[i]] <= k){
					return true;
				}
				table[nums[i]] = i;
			}
		}
		return false;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.containsNearbyDuplicate(vector<int>{3, 1, 5, 2, 1}, 2) << endl;
	system("pause");
	return 0;
}