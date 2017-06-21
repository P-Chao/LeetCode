#include <iostream>
#include <vector>

using namespace std;

class Trie {
public:
	struct Node{
		bool isword;
		vector<Node*> chl;
		Node() : chl(vector<Node*>(26,NULL)), isword(false){};
	};

	Node *root = NULL;
	/** Initialize your data structure here. */
	Trie() {
		root = new Node;
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		Node *node = root;
		const int n = word.size();
		for (int i = 0; i < n; ++i){
			int t = word[i] - 'a';
			if (node->chl[t] == NULL){
				node->chl[t] = new Node;
			}
			node = node->chl[t];
		}
		node->isword = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		Node *node = root;
		const int n = word.size();
		for (int i = 0; i < n; ++i){
			int t = word[i] - 'a';
			if (node->chl[t] == NULL){
				return false;
			}
			node = node->chl[t];
		}
		return node->isword;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		Node *node = root;
		const int n = prefix.size();
		for (int i = 0; i < n; ++i){
			int t = prefix[i] - 'a';
			if (node->chl[t] == NULL){
				return false;
			}
			node = node->chl[t];
		}
		return true;
	}
};

int main(int argc, char *argv[]){
	Trie obj;
	obj.insert("asdf");
	cout << obj.search("asdf") << endl;
	cout << obj.startsWith("afsd") << endl;
	system("pause");
	return 0;
}
