#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Solution: https://discuss.leetcode.com/topic/82880/c-two-end-bfs-and-backtracking-45ms-clearly-commented

class Solution {
/*
	Idea :
	1. use two-end bfs to iteratively find the shortest path
	2. use a map of [nextNode, curNodeList] to record all possible paths to the nextNode for the purpose of backtracing
	3. use a boolean to represent the end of bfs, a boolean to represent the swap of head and tail
	4. use dfs to recursivlely backtrace

	Caution and more ideas : see comments
*/
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList){
		unordered_set<string> s;
		for (auto item : wordList){
			s.insert(item);
		}
		if (s.find(endWord) == s.end()){
			return{};
		}

		unordered_map<string, unordered_set<string>> backtrace;
		unordered_set<string> head({ beginWord }), tail({endWord});
		bool reverse = false, finish = false;

		s.erase(beginWord); s.erase(endWord);
		while (!head.empty() && !tail.empty() && !finish){
			// two-end bfs: swap head and tail to reach balence of two sets
			// for optimized performance
			if (head.size() > tail.size()){
				reverse = !reverse;
				swap(head, tail);
			}
			// temp will contain neighbors of the current level nodes, so this is bfs
			unordered_set<string> temp;
			for (auto item : head){
				for (int l = 0; l < item.size(); ++l){ // 对单词中每个字母进行26个字母的替换
					string ori = item;
					// O(26 * size of item)
					for (char c = 'a'; c <= 'z'; ++c){
						item[l] = c;
						if (tail.find(item) != tail.end()){  // 查寻等于尾部节点
							if (!reverse){
								backtrace[item].insert(ori); // backtrace 是用来记录路径的邻接链表 map<string,vec<string>>， string中的每个元素都与vec<string>中的元素相差一个字符，这个连接是带有方向的，保证在dfs时不出现更长的字符串
							} else{
								backtrace[ori].insert(item);
							}
							finish = true;
						} else if (s.find(item) != s.end()){ // 在没有查找到尾部节点的情况下,在词典中查找
							temp.insert(item);               // 搜索新起点
							if (!reverse){
								backtrace[item].insert(ori); // backtrace被用来记录路径，方式为邻接链表
							} else{
								backtrace[ori].insert(item); 
							}
						}
					}
					item = ori;  // 与前面ori=item相呼应，这里进行的是item的还原
				}
			}
			// only delete items after we finish iterating the current level
			// if we delete while iterating, it is possible that we delete a
			// node whice has two sources to reach it
			for (auto item : temp){ // because all temp are visited，这里注意，不立即标识visitied，而在访问完一层之后标识visited，就是为了在bfs时不会引起一些路径的丢失,finish 也是一轮之后才生效，这样才能找到所有最短的结果
				s.erase(item);
			}
			head = temp;
		}

		vector<vector<string>> ret;
		vector<string> temp({endWord});
		backtrack(ret, backtrace, temp, endWord, beginWord);  // recover paths

		return ret;
	}

private:
	void backtrack(vector<vector<string>> &ret,
		unordered_map<string, unordered_set<string>>& backtrace,
		vector<string>& temp,
		string endWord,
		string beginWord){

		if (endWord == beginWord){   // 剪枝条件
			vector<string> rev = temp;
			reverse(rev.begin(), rev.end());
			ret.push_back(rev);
			return;
		}

		for (auto item : backtrace[endWord]){ // 在最后到达endWord的所有结果进行DFS回溯
			temp.push_back(item);
			backtrack(ret, backtrace, temp, item, beginWord); // endWord是深度优先搜索的变化量
			temp.pop_back();
		}
		return;
	}

	vector<vector<string>> findLaddersMyNotFinished(string beginWord, string endWord, vector<string>& wordList) {
		vector<vector<string>> res;
		const int n = wordList.size();
		if (n == 0){
			return res;
		}
		const int m = wordList[0].size();

		// build connect map;
		vector<vector<int>> connect(n);
		for (int i = 0; i < n; ++i){
			for (int j = i + 1; j < n; ++j){
				int cnt = 0;
				for (int k = 0; k < m; ++k){
					if (wordList[i][m] != wordList[j][m]){
						cnt++;
					}
				}
				if (cnt == 1){
					connect[i].push_back(j);
					connect[j].push_back(i);
				}
			}
		}

		vector<bool> toend(n, false);

		queue<int> q;
		for (int i = 0; i < n; ++i){
			int cnt1 = 0, cnt2 = 0;
			for (int k = 0; k < n; ++k){
				if (wordList[m][k] != beginWord[k]){
					cnt1++;
				}
				if (wordList[m][k] != endWord[k]){
					cnt2++;
				}
			}
			if (cnt1 == 1){
				q.push(i);
			}
			if (cnt2 == 1){
				toend[i] = true;
			}
		}

		vector<bool> visited(n + 1, false);

		while (!q.empty()){
			int nd = q.front(); q.pop();
			if (toend[nd]){
				// get
				continue;
			}
			for (int i = 0; i < connect[nd].size(); ++i){
				int id = connect[nd][i];
				if (toend[id]){
					// get
					continue;
				}
				if (visited[connect[nd][i]]){
					continue;
				}
				visited[connect[nd][i]] = true;
				q.push(id);
			}
		}

	}

};

int main(int argc, char *argv[]){
	Solution s;
	auto rs = s.findLadders("hit", "cog", vector<string>{ "hot", "dot", "dog", "lot", "log", "cog" });
	for (auto vstr : rs){
		for (auto str : vstr){
			cout << str << ", ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}