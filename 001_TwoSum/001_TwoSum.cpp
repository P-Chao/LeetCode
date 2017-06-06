#include <iostream>
#include <vector>
#include <hash_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		hash_map<int, int> m; // unordered_map
		for (int i = 0; i < nums.size(); ++i){
			if (m.count(target - nums[i])){
				return{m[target - nums[i]], i};
			}
			m[nums[i]] = i;
		}
		return{};
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto v = s.twoSum(vector<int>{2, 7, 11, 15}, 9);
	if (v.size() == 2){
		cout << v[0] << ", " << v[1] << endl;
	}
	system("pause");
	return 0;
}