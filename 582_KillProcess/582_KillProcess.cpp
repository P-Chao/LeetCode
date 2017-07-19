#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
		if (kill == 0){
			return{};
		}
		unordered_map<int, vector<int>> graph;
		const int n = pid.size();
		for (int i = 0; i < n; ++i){
			graph[ppid[i]].push_back(pid[i]);
		}
		vector<int> res;
		queue<int> q;
		q.push(kill);
		while (!q.empty()){
			auto t = q.front();
			res.push_back(t);
			q.pop();
			for (int i = 0; i < graph[t].size(); ++i){
				q.push(graph[t][i]);
			}
		}
		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto vs = s.killProcess(vector<int>{1, 2, 10, 5}, vector<int>{3, 0, 5, 3}, 5);
	for (auto v : vs){
		cout << v << ", ";
	}
	system("pause");
	return 0;
}