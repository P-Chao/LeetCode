#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		if (!nums.size()) return 0;
		int res = nums[0];
		for (int i = 1; i<nums.size(); i++){
			res = res ^ nums[i];
		}
		return res;
	}

	int singleNumberMy(vector<int>& nums) {
		unordered_set<int> st;
		long long sum = 0;
		for (auto num : nums){
			if (st.count(num) == 1){
				st.erase(num);
				sum -= num;
			} else{
				st.insert(num);
				sum += num;
			}
		}
		return (int)sum;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.singleNumber(vector<int>{1, 1, 2, 3, 2}) << endl;
	system("pause");
	return 0;
}