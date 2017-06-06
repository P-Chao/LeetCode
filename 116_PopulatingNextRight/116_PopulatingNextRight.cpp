#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode* root){ //only for perfect tree
		if (!root){
			return;
		}
		TreeLinkNode* curLev;
		while (root->left){
			curLev = root;
			while (curLev){
				curLev->left->next = curLev->right;
				if (curLev->next){
					curLev->right->next = curLev->next->left;
				}
				curLev = curLev->next;
			}
			root = root->left;
		}
		return;
	}

	void connectExSpace(TreeLinkNode *root) {
		if (!root){
			return;
		}
		queue<TreeLinkNode*> q;
		TreeLinkNode* pre = NULL;
		q.push(root);
		q.push(NULL);
		while (!q.empty()){
			auto t = q.front();
			q.pop();
			if (pre){
				pre->next = t;
			}
			pre = t;
			if (t){
				if (t->left){
					q.push(t->left);
				}
				if (t->right){
					q.push(t->right);
				}
			} else{
				if (!q.empty()){
					q.push(NULL);
				}
			}
		}
		return;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	s.connect(NULL);
	system("pause");
	return 0;
}