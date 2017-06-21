#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> res;
		const int n = nums.size();
		if (n == 0){
			return{};
		}
		
		char buf[50];
		int start = nums[0];
		int end = 0;
		for (int i = 1; i < n+1; ++i){
			if (i == n || nums[i] - nums[i - 1] != 1){
				end = nums[i - 1];
				if (start == end){
					sprintf(buf, "%d", start);
				} else{
					sprintf(buf, "%d->%d", start, end);
				}
				res.push_back(string(buf));
				if (i != n){
					start = nums[i];
				}
			}
		}
		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto vs = s.summaryRanges(vector<int>{0, 1, 2, 4, 5, 7});
	for (auto v : vs){
		cout << v << ", ";
	}
	system("pause");
	return 0;
}