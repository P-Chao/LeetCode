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
	int pathSum(TreeNode* root, int sum) {
		if (!root){
			return 0;
		}
		target = sum;
		count = 0;
		vector<int> pathsum;
		pathsum.push_back(0);
		dfs(root, pathsum);
		return count;
	}

private:
	int dfs(TreeNode* node, vector<int>& pathsum){
		if (!node){
			return;
		}
		int prev = pathsum.back();
		for (auto v : pathsum){
			if (pathsum.back() + node->val - v == target){
				++count;
			}
		}
		if (node->left){
			pathsum.push_back(prev + node->val);
			dfs(node->left, pathsum);
			pathsum.pop_back();
		}
		if (node->right){
			pathsum.push_back(prev + node->val);
			dfs(node->right, pathsum);
			pathsum.pop_back();
		}
	}
	int count;
	int target;
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.pathSum(NULL, 0) << endl;
	system("pause");
	return 0;
}