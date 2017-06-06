#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	int maxPoints(vector<Point>& points) { // 使用最大公约数表示斜率，避免第二题long double的精度不足
		unordered_map<pair<int, int>, int> slopes;
		int maxp = 0, n = points.size();
		for (int i = 0; i < n; i++) {
			slopes.clear();
			int duplicate = 1;
			for (int j = i + 1; j < n; j++) {
				if (points[j].x == points[i].x && points[j].y == points[i].y) {
					duplicate++;
					continue;
				}
				int dx = points[j].x - points[i].x;
				int dy = points[j].y - points[i].y;
				int dvs = gcd(dx, dy);
				slopes[make_pair(dx / dvs, dy / dvs)]++;
			}
			maxp = max(maxp, duplicate);
			for (auto slope : slopes)
				if (slope.second + duplicate > maxp)
					maxp = slope.second + duplicate;
		}
		return maxp;
	}
private:
	int gcd(int num1, int num2) { // 辗转相除法
		while (num2) {
			int temp = num2;
			num2 = num1 % num2;
			num1 = temp;
		}
		return num1;
	}

public:
	int maxPointsLD(vector<Point>& points) {
		const int n = points.size();
		if (n < 3){
			return n;
		}
		int res = 0;
		for (int i = 0; i < n; ++i){
			int same = 0;
			unordered_map<long double, int> mp;
			for (int j = 0; j < n; ++j){
				int dx = points[j].x - points[i].x;
				int dy = points[j].y - points[i].y;
				if (dy == 0 && dx == 0){
					same++;
					continue;
				}
				if (dx == 0){
					mp[(long double)INT_MAX]++;
				} else{
					mp[(long double)dy / dx]++;
				}
			}

			if (same > res){
				res = same;
			}
			for (auto val : mp){
				if (res < val.second + same){
					res = val.second + same;
				}
			}
		}
		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.maxPoints(vector<Point>{Point(0, 0), Point(1, 1), Point(1, -1)}) << endl;
	system("pause");
	return 0;
}