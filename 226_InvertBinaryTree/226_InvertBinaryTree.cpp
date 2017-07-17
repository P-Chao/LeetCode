#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root){
			auto t = root->left;
			root->left = invertTree(root->right);
			root->right = invertTree(t);
		}
		return root;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto t = s.invertTree(NULL);
	system("pause");
	return 0;
}