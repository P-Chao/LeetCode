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
	TreeNode* deleteNode(TreeNode* root, int key){
		if (!root){
			return NULL;
		}
		if (root->val > key){
			root->left = deleteNode(root->left, key);
		} else if (root->val < key){
			root->right = deleteNode(root->right, key);
		} else{
			if (!root->right){
				return root->left;
			}
			TreeNode* cur = root->right;
			while (cur->left){
				cur = cur->left;
			}
			swap(root->val, cur->val);
			root->right = deleteNode(root->right, key);
		}
		return root;
	}

	TreeNode* deleteNodeMyIt(TreeNode* root, int key) {
		if (!root){
			return root;
		}
		TreeNode dummy(0);
		dummy.left = root;
		TreeNode *t = root;
		TreeNode **par = &dummy.left;
		while (t){
			if (t->val == key){
				break;
			}
			if (t->val > key){
				par = &t->left;
				t = t->left;
			} else{
				par = &t->right;
				t = t->right;
			}
		}

		if (!t){
			return dummy.left;
		}

		if (!t->left && !t->right){
			*par = NULL;
		} else if (!t->left && t->right){
			*par = t->right;
		} else if (t->left && !t->right){
			*par = t->left;
		} else{
			auto s = t->right; // ºó¼Ì
			auto p = &t->right;
			while (s->left){
				p = &s->left;
				s = s->left;
			}
			*p = s->right;
			*par = s;
			s->left = t->left;
			s->right = t->right;
		}
		return dummy.left;
	}

};

int main(int argc, char *argv[]){
	Solution s;
	auto t = BuildTree(vector<int>{5, 4, 3, 2, 1});
	t = s.deleteNode(t, 3);
	PrintTree(t);
	system("pause");
	return 0;
}