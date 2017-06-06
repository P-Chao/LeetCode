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

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) { // reco
		if (!root){
			return{};
		}
		vector<int> path;
		TreeNode* prev = NULL;
		stack<TreeNode*> stk;
		stk.push(root);
		while (!stk.empty()){
			auto t = stk.top();
			if ((!t->left && !t->right) || // t是叶节点，或者
				(prev && (t->left == prev || t->right == prev))){ // t有孩子刚刚遍历过
				path.push_back(t->val);
				stk.pop();
				prev = t;
			} else{
				if (t->right){
					stk.push(t->right);
				}
				if (t->left){
					stk.push(t->left);
				}
			}
		}
		return path;
	}

	vector<int> postorderTraversalII(TreeNode* root){
		vector<int> path;
		stack<TreeNode*> stk;
		TreeNode* cur = root, *prev = NULL;
		while (cur || !stk.empty()){
			if (cur){
				stk.push(cur);
				cur = cur->left;
			} else{
				TreeNode* t = stk.top();
				if (t->right && t->right != prev){
					cur = t->right;
				} else{
					path.push_back(t->val);
					stk.pop();
					prev = t;
				}
			}
		}
		return path;
	}
	
};

int main(int argc, char *argv[]){
	Solution s;
	s.postorderTraversal(NULL);
	system("pause");
	return 0;
}