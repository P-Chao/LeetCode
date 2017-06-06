#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

ListNode* BuildList(vector<int>& nums){
	ListNode *list = new ListNode(0);
	ListNode *head = list;
	for (auto v : nums){
		list->next = new ListNode(v);
		list = list->next;
	}
	return head->next;
}

void PrintTreeInorder(TreeNode *root){
	if (!root){
		return;
	}
	PrintTreeInorder(root->left);
	cout << root->val << ",";
	PrintTreeInorder(root->right);
	return;
}

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		return toBST(head, NULL);
	}
private:
	TreeNode* toBST(ListNode* start, ListNode* end){
		if (start == end){
			return NULL;
		}
		if (start->next == end){
			return new TreeNode(start->val);
		}

		ListNode *fast = start, *slow = start;
		while (fast != end && fast->next != end) {
			fast = fast->next->next;
			slow = slow->next;
		}

		TreeNode *tree = new TreeNode(slow->val); // 最后一个节点是不会处理的，作为根节点
		tree->left = toBST(start, slow);
		tree->right = toBST(slow->next, end);
		
		return tree;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto l = BuildList(vector<int>{1, 2, 3, 3, 7});
	auto t = s.sortedListToBST(l);
	PrintTreeInorder(t);
	system("pause");
	return 0;
}