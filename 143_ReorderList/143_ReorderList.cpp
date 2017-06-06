#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
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

void PrintList(ListNode* list){
	ListNode * nd = new ListNode(0);
	nd->next = list;
	while (nd->next){
		nd = nd->next;
		cout << nd->val << ", ";
	}
	return;
}

class Solution {
public:
	void reorderList(ListNode* head) {
		if (head == NULL || head->next == NULL){
			return;
		}
		ListNode* fast = head, *slow = head;
		while (fast && fast->next){
			fast = fast->next->next;
			slow = slow->next;
		}
		// slow ¿ªÊ¼·´Ðò
		ListNode* midend = slow;
		ListNode* hd = NULL;
		while (slow){
			auto tmp = slow->next;
			slow->next = hd;
			hd = slow;
			slow = tmp;
		}
		// reorder
		ListNode *l = head, *r = hd;
		while (l != NULL && r != NULL){
			if (l->next == midend && r->next == NULL){
				l->next = NULL;
			}
			auto tmp = l->next;
			l->next = r;
			l = tmp;
			tmp = r->next;
			r->next = l;
			r = tmp;
		}
		return;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto l = BuildList(vector<int>{1, 2, 3, 4});
	s.reorderList(l);
	PrintList(l);
	system("pause");
	return 0;
}