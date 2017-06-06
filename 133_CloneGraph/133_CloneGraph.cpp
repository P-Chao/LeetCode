#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

//Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (!node){
			return node;
		}
		map<UndirectedGraphNode *, UndirectedGraphNode *> m;
		queue<UndirectedGraphNode *> q;
		UndirectedGraphNode *newGraph = new UndirectedGraphNode(node->label);
		m.insert({ node, newGraph });
		q.push(node);
		while (!q.empty()){
			auto t = q.front();
			auto g = m[t];
			q.pop();
			for (auto n : t->neighbors){
				if (m.find(n) == m.end()){
					m[n] = new UndirectedGraphNode(n->label);
					q.push(n);
				}
				g->neighbors.push_back(m[n]);
			}
		}
		return newGraph;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto g = s.cloneGraph(NULL);
	system("pause");
	return 0;
}