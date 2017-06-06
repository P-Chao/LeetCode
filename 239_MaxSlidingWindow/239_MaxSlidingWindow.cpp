#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindowOld(vector<int>& nums, int k) {
		vector<int> maxvec(nums.size()-k+1, 0);
		priority_queue<int> pq;
		if (k < 2){
			return nums;
		}
		const int j = k - 1;
		for (int m = 0; m < maxvec.size(); ++m){
			maxvec[m] = *max_element(nums.begin() + m, nums.begin() + m + j);
		}
		return maxvec;
	}

	vector<int> maxSlidingWindow(vector<int>& nums, int k) { //DQ
		vector<int> res;
		deque<int> q; // 双向队列保存数组下标
		for (int i = 0; i < nums.size(); ++i) {
			if (!q.empty() && q.front() == i - k) {
				q.pop_front(); // 这个数字已经不再区间内了，所以删除
			}
			while (!q.empty() && nums[q.back()] < nums[i]) { 
				q.pop_back(); // 如果将要进来的值比队尾的值大，则队尾的值都删除(这些值都已经失效)，保证了最大值在队列最前面
			}
			q.push_back(i);
			if (i >= k - 1) {
				res.push_back(nums[q.front()]); // 经过前面的筛选之后，队首的值就是这个区间的最大值
			}
		}
		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	vector<int> v{0, 1, 2, 5, 3, 5, 5, 6, 7};
	auto r = s.maxSlidingWindow(v, 3);
	for (auto t : r){
		cout << t << ", ";
	}
	system("pause");
	return 0;
}
