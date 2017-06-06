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
		} else {
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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return helper(nums);
	}

private:
	TreeNode* helper(vector<int>& nums){
		int n = nums.size();
		if (n == 0){
			return NULL;
		}
		if (n == 1){
			return new TreeNode(nums[0]);
		}
		int m = n / 2;
		TreeNode *root = new TreeNode(nums[m]);
		auto left = vector<int>(nums.begin(), nums.begin() + m);
		auto right = vector<int>(nums.begin() + m + 1, nums.end());
		root->left = helper(left);
		root->right = helper(right);
		return root;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto t = s.sortedArrayToBST(vector<int>{1, 2, 3, 4, 5});
	PrintTree(t);
	system("pause");
	return 0;
}
