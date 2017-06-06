#include <iostream>
#include <vector>
#include <queue>
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

void PrintTree(TreeNode* root){
	vector<vector<int> >  result;
	if (!root) return;
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);
	vector<int> cur_vec;
	while (!q.empty()) {
		TreeNode* t = q.front();
		q.pop();
		if (t == NULL) {
			result.push_back(cur_vec);
			cur_vec.resize(0);
			if (q.size() > 0) {
				q.push(NULL);
			}
		}
		else {
			cur_vec.push_back(t->val);
			if (t->left) q.push(t->left);
			if (t->right) q.push(t->right);
		}
	}
	for (auto vv : result){
		for (auto v : vv){
			cout << v << ", ";
		}
		cout << endl;
	}
	return;
}

class Solution {
public:
	void flatten(TreeNode* root){
		while (root){
			if (root->left && root->right){
				TreeNode* t = root->left;
				while (t->right){
					t = t->right;
				}
				t->right = root->right;
			}
			if (root->left){
				root->right = root->left;
			}
			root->left = NULL;
			root = root->right;
		}
		return;
	}

	void flattenMy(TreeNode* root) {
		if (!root){
			return;
		}
		TreeNode dummy(0);
		dummy.right = root;
		stack<TreeNode*> stk;
		TreeNode* pre = &dummy;
		stk.push(root);
		while (!stk.empty()){
			auto t = stk.top();
			stk.pop();
			if (t->right){
				stk.push(t->right);
			}
			if (t->left){
				stk.push(t->left);
			}
			pre->right = t;
			pre->left = NULL;
			pre = t;
		}
		return;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto t = BuildTree(vector<int>{1, 2, 3, 4});
	s.flatten(t);
	PrintTree(t);
	system("pause");
	return 0;
}