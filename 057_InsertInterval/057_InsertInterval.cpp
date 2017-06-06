/*
LeetCode 057
Peng Chao, 3,Apr
Line: 52
*/

#include <iostream>
#include <vector>

using namespace std;

struct Interval{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e){}
};

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> result;
		// check
		for (auto &interval : intervals){
			if (interval.start > newInterval.end || interval.end < newInterval.start){
				result.push_back(interval);
			} else if (interval.start < newInterval.start &&
				interval.end >= newInterval.start && interval.end <= newInterval.end){
				newInterval.start = interval.start;
			} else if (interval.start >= newInterval.start && interval.start <= newInterval.end &&
				interval.end > newInterval.end){
				newInterval.end = interval.end;
			} else if (interval.start <= newInterval.start && interval.end >= newInterval.end){
				return intervals;
			}
		}
		const int len = result.size();
		for (int i = 0; i < len; ++i){
			if (result[i].start > newInterval.start){
				result.insert(result.begin() + i, newInterval);
				return result;
			}
		}
		result.push_back(newInterval);
		return result;
	}
};

int main(int argc, char *argv[]){
	return 0;
}
