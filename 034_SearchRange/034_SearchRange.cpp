#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		const int n = nums.size();
		int l = 0, r = n-1, m = 0;
		bool isfound = false;
		while (l <= r){
			m = (l + r) / 2;
			int mv = nums[m];
			if (mv == target){
				isfound = true;
				break;
			} else if (mv < target){
				l = m + 1;
			} else{
				r = m - 1;
			}
		}
		
		if (!isfound){
			return{ -1, -1 };
		}

		int ll = l, lr = m, rl = m, rr = r;
		int ml = m, mr = m;

		while (ll <= lr){
			m = (ll + lr) / 2;
			int mv = nums[m];
			if (mv == target){
				ml = m;
				lr = m - 1;
			} else if (mv < target){
				ll = m + 1;
			} else{
				lr = m - 1;
			}
		}

		while (rl <= rr){
			m = (rl + rr) / 2;
			int mv = nums[m];
			if (mv == target){
				mr = m;
				rl = m + 1;
			} else if (mv < target){
				rl = m + 1;
			} else{
				rr = m - 1;
			}
		}

		return{ml, mr};
		
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto v = s.searchRange(vector<int>{ 1 }, 1);
	cout << v[0] << ", " << v[1] << endl;
	system("pause");
	return 0;
}