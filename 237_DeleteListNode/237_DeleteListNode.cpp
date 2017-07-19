#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void deleteNode(ListNode* node) {
		if (!node || !node->next){
			return;
		}
		node->val = node->next->val;
		node->next = node->next->next;
		return;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	s.deleteNode(NULL);
	system("pause");
	return 0;
}