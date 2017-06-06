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
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root){
			return false;
		}
		stack<pair<TreeNode*, int>> stk;
		stk.push({root, root->val});
		while (!stk.empty()){
			auto t = stk.top();
			stk.pop();
			if (!t.first->left && !t.first->right && t.second == sum){
				return true;
			}
			if (t.first->right) {
				stk.push({t.first->right, t.second + t.first->right->val});
			}
			if (t.first->left) {
				stk.push({t.first->left, t.second + t.first->left->val});
			}
		}
		return false;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto t = BuildTree(vector<int>{1, 2, 3, 4});
	cout << s.hasPathSum(t, 9) << endl;
	system("pause");
	return 0;
}