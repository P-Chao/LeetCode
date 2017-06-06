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
	int minDepth(TreeNode* root) {
		if (!root){
			return 0;
		}
		int h = 1;
		queue<TreeNode*> q;
		q.push(root);
		q.push(NULL);
		while (!q.empty()) {
			auto t = q.front();
			q.pop();
			if (t){
				if (!t->left && !t->right){
					return h;
				}
				if (t->left){
					q.push(t->left);
				}
				if (t->right){
					q.push(t->right);
				}
			} else{
				h++;
				if (!q.empty()){
					q.push(NULL);
				}
			}

		}
		return h;
	}

};

int main(int argc, char *argv[]){
	Solution s;
	auto l = BuildTree(vector<int>{1, 2, 3});
	cout << s.minDepth(l) << endl;
	system("pause");
	return 0;
}
