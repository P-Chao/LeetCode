#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int jump(vector<int>& nums){ // BFS
		const int n = nums.size();
		if (n < 2){
			return 0;
		}
		int level = 0, curmax = 0, i = 0, nextmax = 0;
		while (curmax - i + 1 > 0){
			level++;
			for (; i <= curmax; ++i){
				nextmax = max(nextmax, nums[i]+i);
				if (nextmax >= n - 1){
					return level;
				}
			}
			curmax = nextmax;
		}
		return 0;
	}

	int jumpGreey(vector<int>& nums) {
		const int n = nums.size();
		if (n < 1 || nums[0] == 0){
			return 0;
		}
		int step = 0;
		int cur = 0;
		while (cur < n){
			step++;
			int ed = cur + nums[cur];
			if (ed >= n-1){
				break;
			}
			int mx = cur;
			int mi = 0;
			for (int i = cur + 1; i <= ed; ++i){
				if (i + nums[i] > mx){
					mx = i + nums[i];
					mi = i;
				}
			}
			//if (mx == cur){
				//return 0;
			//}
			cur = mi;
		}
		return step;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.jump(vector<int>{1,1,1,1,1}) << endl;
	system("pause");
	return 0;
}