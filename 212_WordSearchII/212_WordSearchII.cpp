#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	struct Trie{
		vector<Trie*> child;
		bool isWord;
		Trie() : child(vector<Trie*>(26, NULL)), isWord(false){}
	};

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		n1 = board.size();
		if (n1 == 0){
			return{};
		}
		n2 = board[0].size();
		Trie *root = new Trie(), *node;
		for (auto str : words){
			node = root;
			for (auto ch : str){
				if (!node->child[ch - 'a']){
					node->child[ch - 'a'] = new Trie();
				}
				node = node->child[ch - 'a'];
			}
			node->isWord = true;
		}

		for (int i = 0; i < n1; ++i){
			for (int j = 0; j < n2; ++j){
				dfs(i, j, "", root->child[board[i][j]-'a'], board);
			}
		}
		return ans;
	}
private:
	void dfs(int x, int y, string str, Trie *root, vector<vector<char>>& board){
		if (!root || board[x][y] == '#'){
			return;
		}
		str += board[x][y];
		if (root->isWord){
			ans.push_back(str);
			root->isWord = false;
		}
		char ch = board[x][y];
		board[x][y] = '#';
		if (x + 1 < n1 && board[x + 1][y] != '#'){
			dfs(x + 1, y, str, root->child[board[x+1][y]-'a'], board);
		}
		if (x - 1 >= 0 && board[x - 1][y] != '#'){
			dfs(x - 1, y, str, root->child[board[x-1][y]-'a'], board);
		}
		if (y + 1 < n2 && board[x][y + 1] != '#'){
			dfs(x, y + 1, str, root->child[board[x][y+1]-'a'], board);
		}
		if (y - 1 >= 0 && board[x][y - 1] != '#'){
			dfs(x, y - 1, str, root->child[board[x][y-1]-'a'], board);
		}
		board[x][y] = ch;
		return;
	}
	int n1, n2;
	vector<string> ans;
};

int main(int argc, char *argv[]){
	Solution s;
	vector<vector<char>> board{ 
	{ 'o', 'a', 'a', 'n' },
	{ 'e', 't', 'a', 'e' },
	{ 'i', 'h', 'k', 'r' },
	{ 'i', 'f', 'l', 'v' } };
	auto vs = s.findWords(board, vector<string>{"oath", "pea", "eat", "rain"});
	for (auto v : vs){
		cout << v << endl;
	}
	system("pause");
	return 0;
}