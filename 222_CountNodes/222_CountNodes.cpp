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
	int depth(TreeNode *root){
		return root ? (1 + depth(root->left)) : -1;
	}

	int countNodes(TreeNode* root){
		int d = depth(root);
		int level = -1;
		int count = 0;
		while (root) {
			if (depth(root->right) == d - 1){ // 左子树为完美二叉树
				count += (1 << d);
				root = root->right;
			} else{  // depth(root->right) == d - 2 // 右子树为完美二叉树
				count += (1 << (d-1));
				root = root->left;
			}
			++level;
			--d;
		}
		return count;
	}

	int countNodesMy(TreeNode* root){
		if (!root){
			return 0;
		}
		return countNodes(root, -1, -1);
	}

private:
	int countNodes(TreeNode* root, int ldepth, int rdepth){
		if (!root){
			return 0;
		}
		if (ldepth == -1){
			ldepth = 1;
			auto t = root->left;
			while (t){
				ldepth++;
				t = t->left;
			}
		}
		if (rdepth == -1){
			rdepth = 1;
			auto t = root->right;
			while (t){
				rdepth++;
				t = t->right;
			}
		}
		if (ldepth == rdepth){
			return (1 << ldepth) - 1;
		}
		return countNodes(root->left, ldepth - 1, -1) + countNodes(root->right, -1, rdepth - 1) + 1;
	}

public:
	int countNodesOld(TreeNode* root) {
		if (!root){
			return 0;
		}
		int lcnt = 1;
		int rcnt = 1;
		TreeNode *l = root->left, *r = root->right;
		while (l) {
			lcnt++;
			l = l->left;
		}
		while (r) {
			rcnt++;
			r = r->right;
		}
		if (lcnt == rcnt){
			return (1 << lcnt) - 1;
		}
		return countNodes(root->left) + countNodes(root->right) + 1;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto t = BuildTree(vector<int>{1, 2});
	cout << s.countNodes(t) << endl;
	system("pause");
	return 0;
}
