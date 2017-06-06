#include <iostream>
#include <vector>

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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || p == root || q == root){
			return root;
		}
		auto left = lowestCommonAncestor(root->left, p, q);
		auto right = lowestCommonAncestor(root->right, p, q);
		if (left && right){
			return root;
		}
		return left ? left : right;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	s.lowestCommonAncestor(NULL, NULL, NULL);
	system("pause");
	return 0;
}
