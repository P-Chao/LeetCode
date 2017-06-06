#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		const int n1 = nums1.size();
		const int n2 = nums2.size();

		vector<pair<int, int>> res;
		if (k == 0 || n1 == 0 || n2 == 0){
			return res;
		}
		if (k > n1 * n2){
			k = n1 * n2;
		}

		vector<vector<bool>> visited(nums1.size(), vector<bool>(nums2.size(), false));

		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

		pq.push({ nums1[0]+nums2[0], { 0, 0 } }); visited[0][0] = true;
		vector<vector<int>> dir{ { 0, 1 }, {0, 1} };

		while (k--){
			auto t = pq.top(); pq.pop();
			int i = t.second.first, j = t.second.second;
			res.push_back({nums1[i], nums2[j]});
			if (j < n2 - 1 && !visited[i][j+1]){
				pq.push({ nums1[i] + nums2[j+1], { i, j + 1 } });
				visited[i][j + 1] = true;
			}
			if (i < n1 - 1 && !visited[i+1][j]){
				pq.push({ nums1[i+1] + nums2[j], {i+1, j} });
				visited[i + 1][j] = true;
			}
		}
		return res;
	}

};

class SolutionT {
public:
	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		int len1 = nums1.size(), len2 = nums2.size(), cnt = min(k, len1*len2);
		vector<int> index(len1, 0);
		vector<pair<int, int>> ans;
		while (cnt-- > 0)
		{
			int temMin = INT_MAX, m = 0;
			for (int i = 0; i < len1; i++)
				if (index[i] < len2 && nums1[i] + nums2[index[i]] < temMin)
					temMin = nums1[i] + nums2[index[i]], m = i;
			ans.push_back(make_pair(nums1[m], nums2[index[m]++]));
		}
		return ans;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	vector<int> nums1{1, 1, 2};
	vector<int> nums2{1, 2, 3};
	vector<pair<int, int>>& sp = s.kSmallestPairs(nums1, nums2, 10);
	for (auto s : sp){
		cout << s.first << ", " << s.second << endl;
	}
	system("pause");
	return 0;
}