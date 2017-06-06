#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *BuildTree(vector<int> preorder){
	TreeNode dummy(0);
	TreeNode* root = &dummy;
	for (int i = 0; i < preorder.size(); ++i){
		root->left = new TreeNode(preorder[i]);
		root = root->left;
	}
	return dummy.left;
}

class Solution {
public:
	TreeNode* first = NULL;
	TreeNode* second = NULL;
	TreeNode* prev = new TreeNode(INT_MIN);
public:
	void recoverTreeC(TreeNode* root) {
		help(root);
		swap(first->val, second->val);
	}

	void help(TreeNode* root){
		if (root == NULL)  return;
		help(root->left);
		if (first == NULL && prev->val >= root->val)   first = prev;
		if (first != NULL && prev->val >= root->val)   second = root;
		prev = root;
		help(root->right);
	}

	void recoverTree(TreeNode* root) {
		stack<TreeNode*> stk;
		TreeNode *p = root;
		TreeNode *pre = NULL;
		pair<TreeNode*, TreeNode*> pair{NULL, NULL};
		while (p || !stk.empty()){
			while (p){
				stk.push(p);
				p = p->left;
			}
			p = stk.top();
			stk.pop();
			if (pre && pre->val > p->val){
				if (!pair.first){
					pair.first = pre;
					pair.second = p;
				} else{
					pair.second = p;
					break;
				}
			}
			pre = p;
			p = p->right;
		}
		if (pair.first && pair.second){
			swap(pair.first->val, pair.second->val);
		}
		return;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto t = BuildTree(vector<int>{0, 1});
	s.recoverTree(t);
	system("pause");
	return 0;
}
