#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		const int n = nums.size();
		unordered_map<int, int> hash;
		for (int i = 0; i < n; ++i){
			if (hash.find(nums[i]) == hash.end()){
				hash.insert({ nums[i], 0 });
			} else{
				hash[nums[i]]++;
			}
		}
		int cnt = 0, val = nums[0];
		for (auto& m : hash){
			if (m.second > cnt){
				cnt = m.second;
				val = m.first;
			}
		}
		return val;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.majorityElement(vector<int>{}) << endl;
	system("pause");
	return 0;
}