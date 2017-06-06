#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int sumNumbers(TreeNode* root) {
		if (!root){
			return 0;
		}
		int res = 0;
		stack<pair<TreeNode*, int>> stk;
		stk.push({root, root->val});
		while (!stk.empty()){
			auto t = stk.top();
			stk.pop();
			if (!t.first->left && !t.first->right){
				res += t.second;
				continue;
			}
			if (t.first->right){
				stk.push({t.first->right, t.second * 10 + t.first->right->val});
			}
			if (t.first->left){
				stk.push({ t.first->left, t.second * 10 + t.first->left->val });
			}
		}
		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.sumNumbers(NULL) << endl;
	system("pause");
	return 0;
}