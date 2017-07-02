#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {

	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto rv = s.numIslands2(3, 3, vector<pair<int, int>>{{0, 0}, {0, 1}, {1, 2}, {2, 1}});
	for (auto v : rv){
		cout << v << ", ";
	}
	system("pause");
	return 0;
}