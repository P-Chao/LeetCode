#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		if (!prerequisites.size()){
			return true;
		}
		vector<vector<int>> map(numCourses, vector<int>());
		for (int i = 0; i < prerequisites.size(); ++i){
			map[prerequisites[i].first].push_back(prerequisites[i].second);
		}
		vector<bool> visited(numCourses, false);
		for (int i = 0; i < numCourses; ++i){ // 从每个结点开始
			if (!visited[i]){
				vector<bool> onStack(numCourses, false);
				if (hasCycle(map, i, visited, onStack)){
					return false;
				}
			}
		}
		return true;
	}
private:
	bool hasCycle(vector<vector<int>> &map, int i, vector<bool>& visited, vector<bool>& onStack){
		visited[i] = true;
		onStack[i] = true;
		for (int k : map[i]){  // 遍历i结点的邻接表
			if (onStack[k]){  // 在本轮循环中遍历过
				return true;  // 在一次dfs中，可以遍历到遍历过的节点（后向边）
			} else {
				if (hasCycle(map, k, visited, onStack)){
					return true;
				}
			}
		}
		onStack[i] = false;  // Revover , DFS 的标记
		return false;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.canFinish(2, vector<pair<int,int>>{{1, 0}, {0, 1}}) << endl;
	system("pause");
	return 0;
}