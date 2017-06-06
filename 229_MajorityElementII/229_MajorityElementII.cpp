#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		const int n = nums.size();
		int t1 = 0, t2 = 0, n1 = 0, n2 = 0;
		for (int i = 0; i < n; ++i){
			if (n1 != 0 && t1 == nums[i]){
				++n1;
				continue;
			}
			if (n2 != 0 && t2 == nums[i]){
				++n2;
				continue;
			}
			if (n1 == 0){
				t1 = nums[i];
				++n1;
				continue;
			}
			if (n2 == 0){
				t2 = nums[i];
				++n2;
				continue;
			}
			--n1;
			--n2;
		}
		int z1 = 0, z2 = 0; 
		for (int i = 0; i < n; ++i){
			if (n1 > 0){
				if (nums[i] == t1){
					++z1;
				}
			}
			if (n2 > 0){
				if (nums[i] == t2){
					++z2;
				}
			}

		}

		vector<int> ret;
		if (z1 > n / 3){
			ret.push_back(t1);
		}
		if (z2 > n / 3){
			ret.push_back(t2);
		}
		return ret;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto vv = s.majorityElement(vector<int>{1, 1, 2, 3, 2});
	for (auto v : vv){
		cout << v << ", ";
	}
	system("pause");
	return 0;
}
