#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool isRectangleCover(vector<vector<int>>& rectangles) {
		const int n = rectangles.size();
		unordered_map<long long, int> mpcnt;
		int lcx = INT_MAX, lcy = INT_MAX, rcx = 0, rcy = 0;
		long long total_area = 0;
		for (auto& coor : rectangles){
			lcx = min(lcx, coor[0]);
			lcy = min(lcy, coor[1]);
			rcx = max(rcx, coor[2]);
			rcy = max(rcy, coor[3]);
			total_area += (coor[3] - coor[1]) * (coor[2] - coor[0]);
			mpcnt[{coor[0] + ((long long)coor[1] << 32)}]++;
			mpcnt[{coor[0] + ((long long)coor[3] << 32)}]++;
			mpcnt[{coor[2] + ((long long)coor[1] << 32)}]++;
			mpcnt[{coor[2] + ((long long)coor[3] << 32)}]++;
		}
		if (total_area != (rcx - lcx) * (rcy - lcy)){
			return false;
		}
		bool flag = true;
		flag = (flag && (mpcnt[{lcx + ((long long)lcy << 32)}] == 1)); mpcnt.erase({ lcx + ((long long)lcy << 32) });
		flag = (flag && (mpcnt[{lcx + ((long long)rcy << 32)}] == 1)); mpcnt.erase({ lcx + ((long long)rcy << 32) });
		flag = (flag && (mpcnt[{rcx + ((long long)lcy << 32)}] == 1)); mpcnt.erase({ rcx + ((long long)lcy << 32) });
		flag = (flag && (mpcnt[{rcx + ((long long)rcy << 32)}] == 1)); mpcnt.erase({ rcx + ((long long)rcy << 32) });
		if (!flag){
			return false;
		}
		for (auto pt : mpcnt){
			if (pt.second == 4 || pt.second == 2){
				continue;
			} else{
				return false;
			}
		}
		return true;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	vector<vector<int>> rectangles{
		{ 1, 1, 3, 3 },
		{ 3, 1, 4, 2 },
		{ 3, 2, 4, 4 },
		{ 1, 3, 2, 4 },
		{ 2, 3, 3, 4 } };
	cout << s.isRectangleCover(rectangles) << endl;
	system("pause");
	return 0;
}