#include <iostream>
#include <vector>
#include <queue>

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
	bool isBalanced(TreeNode* root){
		if (!root){
			return true;
		}
		return (depth(root) != -1);
	}
private:
	int depth(TreeNode* root){
		if (!root){
			return 0;
		} 
		int leftdepth = depth(root->left);
		int rightdepth = depth(root->right);
		if (leftdepth == -1 || rightdepth == -1 || abs(leftdepth - rightdepth) > 1){
			return -1;
		} else if (leftdepth - rightdepth >= 0){
			return leftdepth + 1;
		} else{
			return rightdepth + 1;
		}
		return 0;
	}

public:
	bool isBalancedMy(TreeNode* root) {
		int h = 0;
		int maxh = INT_MIN, minh = INT_MAX;
		isbalance = true;
		if (!root){
			return true;
		}
		treedeepth(root);
		return isbalance;
	}

private:
	int treedeepth(TreeNode* root){
		if (!isbalance){
			return 0;
		}
		if (!root){
			return 0;
		}
		int leftdeepth = treedeepth(root->left);
		int rightdeepth = treedeepth(root->right);
		if (abs(leftdeepth - rightdeepth) > 1){
			isbalance = false;
		}
		return max(leftdeepth, rightdeepth)+1;
	}
	bool isbalance;
};

int main(int argc, char *argv[]){
	Solution s;
	auto t = BuildTree(vector<int>{1, 2});
	cout << s.isBalanced(t) << endl;
	system("pause");
	return 0;
}