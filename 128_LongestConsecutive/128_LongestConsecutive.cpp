#include <iostream>
#include <vector>
#include <hash_set>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		const int n = nums.size();
		if (n < 2){
			return n;
		}
		unordered_set<int> table(nums.begin(), nums.end()); // hash_set<int>
		
		int max_cnt = 1;
		while (!table.empty()){
			auto it = table.begin();
			int val = *it;
			int cnt = 1;
			table.erase(val);
			int cur = val;
			while (table.count(--cur)){
				cnt++;
				table.erase(cur);
			}
			cur = val;
			while (table.count(++cur)){
				cnt++;
				table.erase(cur);
			}
			if (cnt > max_cnt){
				max_cnt = cnt;
			}
		}
		return max_cnt;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.longestConsecutive(vector<int>{100, 4, 200, 1, 3, 2}) << endl;
	system("pause");
	return 0;
}
