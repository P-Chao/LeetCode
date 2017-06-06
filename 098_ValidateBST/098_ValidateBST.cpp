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
	bool isValidBST(TreeNode* root) {
		if (!root){
			return true;
		}
		// ∑«µ›πÈ÷––Ú±È¿˙
		stack<TreeNode*> stk;
		TreeNode *p = root;
		TreeNode *pre = NULL;
		while (p || !stk.empty()){
			while (p){
				stk.push(p);
				p = p->left;
			}
			p = stk.top();
			stk.pop();
			if (pre && p->val <= pre->val){
				return false;
			}
			pre = p;
			p = p->right;
		}
		return true;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.isValidBST(new TreeNode(0)) << endl;
	system("pause");
	return 0;
}