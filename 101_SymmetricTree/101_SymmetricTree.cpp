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
	bool isSymmetric(TreeNode* root) {
		if (!root){
			return true;
		}
		TreeNode *l = root->left;
		TreeNode *r = root->right;
		return helper(l, r);
	}
private:
	bool helper(TreeNode* l, TreeNode* r){
		if (!l && !r){
			return true;
		}
		if ((l && !r) || (!l && r)){
			return false;
		}
		if (!helper(l->left, r->right)){
			return false;
		}
		if (l->val != r->val){
			return false;
		}
		if (!helper(l->right, r->left)){
			return false;
		}
		return true;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto t = BuildTree(vector<int>{0, 1, 2});
	cout << s.isSymmetric(t) << endl;
	system("pause");
	return 0;
}
