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
	int rob(TreeNode* root){
		auto p = rob2(root);
		return max(p.first, p.second);
	}
private:
	pair<int, int> rob2(TreeNode* node){
		if (!node){
			return{0, 0};
		}
		pair<int, int> p, p1, p2;
		p1 = rob2(node->left);
		p2 = rob2(node->right);
		p.first = node->val + p1.second + p2.second;
		p.second = max(p1.first, p1.second) + max(p2.first, p2.second);
		return p;
	}

public:
	int robMy(TreeNode* root) {
		if (!root){
			return 0;
		}
		int t = root->val;
		int tl = robMy(root->left);
		int tr = robMy(root->right);
		int tll = 0, tlr = 0, trl = 0, trr = 0;
		if (root->left){
			tll = robMy(root->left->left);
			tlr = robMy(root->left->right);
		}
		if (root->right){
			trl = robMy(root->right->left);
			trr = robMy(root->right->right);
		}
		return max(t + tll + tlr + trl + trr, tl + tr);
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto t = BuildTree(vector<int>{1, 3, 5, 7, 9});
	cout << s.rob(t) << endl;
	system("pause");
	return 0;
}