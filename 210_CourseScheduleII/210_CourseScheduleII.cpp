#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<vector<int>> lmp(numCourses, vector<int>());
		vector<pair<int, int>> stampe(numCourses, {0, 0});
		for (auto prereq : prerequisites){
			lmp[prereq.first].push_back(prereq.second);
		}
		int i = 0;
		while (true)
		{
			i++;
		}
		return{};
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto vi = s.findOrder(4, vector<pair<int, int>>{{1, 0}, {2, 0}, {3, 1}, {3, 2}});
	for (auto v : vi){
		cout << v << ", ";
	}
	system("pause");
	return 0;
}