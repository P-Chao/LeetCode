#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head){
			return NULL;
		}
		ListNode dummy(0);
		ListNode* hd = head;
		ListNode* nd = head->next;
		hd->next = NULL;
		while (nd){
			auto t = nd->next;
			nd->next = hd;
			hd = nd;
			nd = t;
		}
		return hd;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	s.reverseList(NULL);
	system("pause");
	return 0;
}