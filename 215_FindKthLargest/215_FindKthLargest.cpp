#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		if (nums.empty()){
			return 0;
		}
		priority_queue<int, vector<int>, greater<int>> pq;
		for (auto num : nums){
			if (pq.size() < k || num > pq.top()){
				pq.push(num);
			}
			if (pq.size() > k){
				pq.pop();
			}
		}
		return pq.top();
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.findKthLargest(vector<int>{2, 1}, 2) << endl;
	system("pause");
	return 0;
}