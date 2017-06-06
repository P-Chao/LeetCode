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
	vector<vector<int>> levelOrder(TreeNode* root){
		vector<vector<int> >  result;
		if (!root) return result;
		queue<TreeNode*> q;
		q.push(root);
		q.push(NULL);
		vector<int> cur_vec;
		while (!q.empty()) {
			TreeNode* t = q.front();
			q.pop();
			if (t == NULL) {
				result.push_back(cur_vec);
				cur_vec.resize(0);
				if (q.size() > 0) {
					q.push(NULL);
				}
			}
			else {
				cur_vec.push_back(t->val);
				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);
			}
		}
		return result;
	}

	vector<vector<int>> levelOrderIt(TreeNode* root) {
		preorder(root, 0);
		return res;
	}
private:
	void preorder(TreeNode* root, int level){
		if (!root){
			return;
		}
		if (res.size() < level + 1){
			res.resize(level+1);
		}
		res[level].push_back(root->val);
		preorder(root->left, level+1);
		preorder(root->right, level+1);
	}
	vector<vector<int>> res;
};

int main(int argc, char *argv[]){
	Solution s;
	auto t = BuildTree(vector<int>{1, 2, 3, 4});
	auto res = s.levelOrder(t);
	for (auto vv : res){
		for (auto v : vv){
			cout << v << ", ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
