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
	int maxPathSum(TreeNode* root) {
		if (!root){
			return 0;
		}
		maxsum = INT_MIN;
		pathSum(root);
		return maxsum;
	}
private:
	int pathSum(TreeNode* node){
		if (!node){
			return 0;
		}
		int curval = node->val;
		int lsum = 0, rsum = 0;
		if (node->left){
			lsum = pathSum(node->left);
			if (lsum > 0){
				curval += lsum;
			}
		}
		if (node->right){
			rsum = pathSum(node->right);
			if (rsum > 0){
				curval += rsum;
			}
		}
		if (curval > maxsum){
			maxsum = curval;
		}
		int single = max(node->val, max(node->val + lsum, node->val + rsum));
		return single;
	}
	int maxsum;
};
int main(int argc, char *argv[]){
	Solution s;
	auto t = BuildTree(vector<int>{1, 2, 3, 4, 5});
	cout << s.maxPathSum(t) << endl;
	system("pause");
	return 0;
}