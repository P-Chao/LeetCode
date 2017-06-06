#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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

void PrintTree(TreeNode* root){
	vector<vector<int> >  result;
	if (!root) return;
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
	for (auto vv : result){
		for (auto v : vv){
			cout << v << ", ";
		}
		cout << endl;
	}
	return;
}

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> paths;
		vector<int> path;
		findPaths(root, sum, path, paths);
		return paths;
	}
private:
	void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int>>& paths){
		if (!node){
			return;
		}
		path.push_back(node->val);
		if (!(node->left) && !(node->right) && sum == node->val){
			paths.push_back(path);
		}
		findPaths(node->left, sum - node->val, path, paths);
		findPaths(node->right, sum - node->val, path, paths);
		path.pop_back();
	}

public:
	vector<vector<int>> pathSumMy(TreeNode* root, int sum) {
		vector<vector<int>> res;
		if (!root){
			return res;
		}
		stack<pair<TreeNode*, pair<int, vector<int>>>> stk;
		stk.push({ root, { root->val, vector<int>{root->val} } });
		while (!stk.empty()) {
			auto t = stk.top();
			stk.pop();
			if (!t.first->left && !t.first->right && t.second.first == sum){
				res.push_back(t.second.second);
			}
			if (t.first->right){
				auto path = t.second.second;
				path.push_back(t.first->right->val);
				stk.push({ t.first->right, { t.first->right->val + t.second.first, path} });
			}
			if (t.first->left){
				auto path = t.second.second;
				path.push_back(t.first->left->val);
				stk.push({ t.first->left, { t.first->left->val + t.second.first, path} });
			}
		}
		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto t = BuildTree(vector<int>{1, 2, 3, 4});
	auto res = s.pathSum(t, 10);
	for (auto vv : res){
		for (auto v : vv){
			cout << v << ", ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}