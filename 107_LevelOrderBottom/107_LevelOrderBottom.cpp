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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;
		vector<int> cur_vec;
		queue<TreeNode*> q;
		if (!root){
			return res;
		}
		q.push(root);
		q.push(NULL);
		while (!q.empty()){
			auto t = q.front();
			q.pop();
			if (t){
				cur_vec.push_back(t->val);
				if (t->left){
					q.push(t->left);
				}
				if (t->right){
					q.push(t->right);
				}
			} else{
				res.push_back(cur_vec);
				cur_vec.clear();
				if (!q.empty()){
					q.push(NULL);
				}
			}
		}
		reverse(res.begin(), res.end());
		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto t = BuildTree(vector<int>{1, 2, 3, 4});
	auto res = s.levelOrderBottom(t);
	for (auto vv : res){
		for (auto v : vv){
			cout << v << ", ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}