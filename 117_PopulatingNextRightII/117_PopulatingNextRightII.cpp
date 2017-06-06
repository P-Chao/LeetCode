#include <iostream>
#include <vector>

using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root){
			return;
		}
		TreeLinkNode* start;
		TreeLinkNode* curNode;
		TreeLinkNode* nextNode;
		while (root){
			start = findStartNodeNextLev(root);
			curNode = start;
			nextNode = findNextNodeNextLev(root, start);
			while (nextNode){
				curNode->next = nextNode;
				curNode = nextNode;
				nextNode = findNextNodeNextLev(root, curNode);
			}
			root = start;
		}
		return;
	}
private:
	TreeLinkNode* findNextNodeNextLev(TreeLinkNode* &cur, TreeLinkNode* curNextLev){
		if (cur->left == curNextLev && cur->right){
			return cur->right;
		} else{
			while (cur->next){
				cur = cur->next;
				if (cur->left && cur->left != curNextLev){
					return cur->left;
				}
				if (cur->right && cur->right != curNextLev){
					return cur->right;
				}
			}
		}
		return NULL;
	}

	TreeLinkNode* findStartNodeNextLev(TreeLinkNode* node){
		if (!node){
			return NULL;
		}
		if (node->left){
			return node->left;
		}
		return findNextNodeNextLev(node, node->left);
	}

};

int main(int argc, char *argv[]){
	Solution s;
	system("pause");
	return 0;
}