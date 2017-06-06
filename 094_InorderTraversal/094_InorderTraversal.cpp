#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		inorder(root);
		return res;
	}
private:
	void inorder(TreeNode* root){
		if (root == NULL){
			return;
		}
		inorder(root->left);
		res.push_back(root->val);
		inorder(root->right);
	}
	vector<int> res;
};

int main(int argc, char *argv){
	Solution s;
	system("pause");
	return 0;
}