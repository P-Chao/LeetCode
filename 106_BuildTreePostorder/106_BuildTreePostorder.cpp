#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return Helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
	}
private:
	TreeNode* Helper(vector<int>& inorder, int inbegin, int inend,
		vector<int>& postorder, int postbegin, int postend){
		if (postbegin > postend){
			return NULL;
		} else if (postbegin == postend){
			return new TreeNode(postorder[postend]);
		}

		TreeNode* root = new TreeNode(postorder[postend]);

		int i = inbegin;
		for (; i <= inend; ++i){
			if (inorder[i] == postorder[postend]){
				break;
			}
		}

		int leftlen = i - inbegin;

		root->left = Helper(inorder, inbegin, i - 1, postorder, postbegin, postbegin + leftlen - 1);
		root->right = Helper(inorder, i + 1, inend, postorder, postbegin + leftlen, postend - 1);

		return root;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	s.buildTree(vector<int>{}, vector<int>{});
	system("pause");
	return 0;
}