#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int res = 0;
		heights.push_back(0); // NIL
		stack<int> si;
		const int n = heights.size();
		for (int i = 0; i < n; ++i){
			while (!si.empty() && heights[i] <= heights[si.top()]) {
				int h = heights[si.top()];
				si.pop();
				int area = h * (si.empty() ? i : (i-si.top()-1));
				res = max(res, area);
			}
			si.push(i);
		}
		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.largestRectangleArea(vector<int>{3, 5, 5, 2, 5, 5, 6, 6, 4, 4, 1, 1, 2, 5, 5, 6, 6, 4, 1, 3}) << endl; // 24
	system("pause");
	return 0;
}