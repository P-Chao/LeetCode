#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		map<long long, int> m;
		int j = 0;
		for (int i = 0; i < nums.size(); ++i){
			if (i - j > k){
				m.erase(nums[j++]);
			}
			auto a = m.lower_bound((long long)nums[i] - t);
			if (a != m.end() && abs(a->first - nums[i]) <= t){
				return true;
			}
			m[nums[i]] = i;
		}
		return false;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.containsNearbyAlmostDuplicate(vector<int>{1, 2, 3, 4}, 3, 2) << endl;
	system("pause");
	return 0;
}
