#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> nu;
		if (n == 0){
			return nu;
		}
		return generateTrees(1, n);
	}
private:
	vector<TreeNode*> generateTrees(int begin, int end){
		vector<TreeNode*> ret;
		if (begin > end){
			ret.push_back(NULL);
		} else if (begin == end){
			TreeNode* node = new TreeNode(begin);
			ret.push_back(node);
		} else{
			for (int i = begin; i <= end; ++i){ // 最后返回的是包含所有子树搭配情况的
				vector<TreeNode*> left = generateTrees(begin, i - 1);
				vector<TreeNode*> right = generateTrees(i + 1, end);
				// 遍历左右子树的所有搭配情况
				for (int l = 0; l < left.size(); ++l){ 
					for (int r = 0; r < right.size(); ++r){
						TreeNode* root = new TreeNode(i); // 每种情况都构建一颗子树
						root->left = left[l];
						root->right = right[r];
						ret.push_back(root);
					}
				}
			}
		}
		return ret;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto vt = s.generateTrees(3);
	system("pause");
	return 0;
}
