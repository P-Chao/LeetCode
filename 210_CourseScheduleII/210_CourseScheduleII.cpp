#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
	// 不断删除度为0的点，BFS方式
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> order;
		vector<int> outd(numCourses, 0);
		unordered_map<int, vector<int>> graph;
		for (auto& ele : prerequisites){
			graph[ele.second].push_back(ele.first);
			outd[ele.first]++;
		}

		queue<int> q;
		for (int i = 0; i < numCourses; ++i){
			if (outd[i] == 0){
				q.push(i);
			}
		}

		while (!q.empty()) {
			int t = q.front();
			q.pop();
			order.push_back(t);
			for (int i = 0; i < graph[t].size(); ++i){
				outd[graph[t][i]]--;
				if (outd[graph[t][i]] == 0){
					q.push(graph[t][i]);
				}
			}
		}
		return (order.size() == numCourses) ? order : vector<int>();
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