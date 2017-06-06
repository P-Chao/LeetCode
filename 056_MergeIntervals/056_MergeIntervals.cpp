#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	struct Interval {
		int start;
		int end;
		Interval() : start(0), end(0) {}
		Interval(int s, int e) : start(s), end(e) {}
	};

	static bool compare(Interval& l, Interval& r){
		return l.start < r.start;
	}

	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> res;
		const int n = intervals.size();
		if (n == 0){
			return res;
		}
		sort(intervals.begin(), intervals.end(), compare);
		int j = 0;
		res.push_back(intervals[0]);
		for (int i = 1; i < n; ++i){
			if (intervals[i].start <= res[j].end){
				res[j].end = max(res[j].end, intervals[i].end);
			} else {
				res.push_back(intervals[i]);
				j++;
			}
		}
		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	system("pause");
	return 0;
}