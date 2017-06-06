#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		// two-end BFS: 
		// 1) when to use? when the two ends are given, then we can start from both end to speed up the search process. 
		// 2) even we start from both ends, every iteration we only go one-level further. thus we choose the one with smaller size (has fewer neighbors) to process.
		if (wordList.size() == 0) return 0;
		unordered_set<string> dict(wordList.begin(), wordList.end());
		if (dict.find(endWord) == dict.end()) return 0;

		unordered_set<string> head, tail, *phead, *ptail;
		head.insert(beginWord);
		tail.insert(endWord);

		int dist = 1;
		while (!head.empty() && !tail.empty()) {
			dist++;
			// phead always points to the smaller set
			if (head.size() <= tail.size()) { // phead always moves forward
				phead = &head;
				ptail = &tail;  // ptail provides the target node for phead to search for 
			}
			else {
				phead = &tail;
				ptail = &head;
			}
			unordered_set<string> neighbors;
			for (auto iter = phead->begin(); iter != phead->end(); ++iter) {
				string s = *iter;
				for (int i = 0; i < s.size(); ++i) {
					char c = s[i];
					for (int j = 0; j < 26; ++j) {
						s[i] = 'a' + j;
						if (ptail->find(s) != ptail->end()) {  // phead and ptail meet at the same word
							return dist;
						}
						if (dict.find(s) != dict.end()) {
							neighbors.insert(s);
							dict.erase(s);
						}
					}
					s[i] = c;
				}
			}
			swap(*phead, neighbors); // here we use *phead to refer the processed smaller queue
		}
		return 0;
	}

	int ladderLengthMyBFS(string beginWord, string endWord, vector<string>& wordList) {
		const int n = wordList.size();
		if (n == 0){
			return 0;
		}
		vector<bool> visited(n, false);

		queue<int> q;
		for (int i = 0; i < n; ++i){
			if (isLadder(beginWord, wordList[i])){
				q.push(i);
				visited[i] = true;
			}
		}
		q.push(-1);
		int res = 2;
		while (!q.empty()) {
			auto t = q.front();
			q.pop();
			if (t == -1){
				res++;
				if (!q.empty()){
					q.push(-1);
				}
				continue;
			}
			if (wordList[t] == endWord){
				return res;
			}
			for (int i = 0; i < n; ++i){
				if (!visited[i] && i != t && isLadder(wordList[i], wordList[t])){
					q.push(i);
					visited[i] = true;
				}
			}
		}
		return 0;
	}

private:
	bool isLadder(string a, string b){
		int m = a.size();
		int cnt = 0;
		for (int i = 0; i < m; ++i){
			if (a[i] != b[i]){
				cnt++;
			}
		}
		return cnt == 1;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.ladderLength("hit", "cog", vector<string>{"hot", "dot", "dog", "lot", "log"}) << endl;
	system("pause");
	return 0;
}