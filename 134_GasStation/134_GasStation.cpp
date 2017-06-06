#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		const int n = gas.size();
		int cum = 0, min = INT_MAX, minid = -1;
		for (int i = 0; i < n; ++i){
			int tmp = gas[i] - cost[i];
			cum += tmp;
			if (cum < min){
				min = cum;
				minid = i + 1;
			}
		}
		if (minid == n){
			minid = 0;
		}
		return (cum < 0) ? -1 : minid;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.canCompleteCircuit(vector<int>{4}, vector<int>{5}) << endl;
	system("pause");
	return 0;
}