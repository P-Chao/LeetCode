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

class BSTIterator {
private:
	stack<TreeNode*> st;
public:
	BSTIterator(TreeNode *root) {
		find_left(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		if (st.empty())
			return false;
		return true;
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* top = st.top();
		st.pop();
		if (top->right != NULL)
			find_left(top->right);

		return top->val;
	}

	/** put all the left child() of root */
	void find_left(TreeNode* root){
		TreeNode* p = root;
		while (p != NULL){
			st.push(p);
			p = p->left;
		}
	}
};

class BSTIteratorMy {
public:
	BSTIteratorMy(TreeNode *root) {
		p = root;
		/*while (p || !stk.empty()){
			while (p){
				stk.push(p);
				p = p->left;
			}
			p = stk.top();
			stk.pop();
			cout << p->val;
			p = p->right;
		}*/
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return (p || !stk.empty());
	}

	/** @return the next smallest number */
	int next() {
		int val = 0;
		if (p || !stk.empty()){
			while (p){
				stk.push(p);
				p = p->left;
			}
			p = stk.top();
			stk.pop();
			val = p->val;
			p = p->right;
		}
		return val;
	}

private:
	TreeNode *p;
	stack<TreeNode*> stk;
};

int main(int argc, char *argv[]){
	auto t = BuildTree(vector<int>{1, 4, 5, 4, 3});
	BSTIterator i = BSTIterator(t);
	while (i.hasNext()) {
		cout << i.next();
	}
	system("pause");
	return 0;
}
