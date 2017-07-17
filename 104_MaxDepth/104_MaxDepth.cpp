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
	int maxDepth(TreeNode* root) {
		maxdepth = 0;
		if (root){
			dfs(root, 1);
		}
		return maxdepth;
	}
private:
	void dfs(TreeNode* node, int depth){
		if (node->left){
			dfs(node->left, depth+1);
		}
		if (node->right){
			dfs(node->right, depth+1);
		}
		if (!node->left && !node->right){
			if (depth > maxdepth){
				maxdepth = depth;
			}
		}
	}
	int maxdepth;
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.maxDepth(NULL) << endl;
	system("pause");
	return 0;
}