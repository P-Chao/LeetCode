#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

	}
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