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
	ListNode* swapPairs(ListNode* head) {
		ListNode *a1 = head;
		if (!a1){
			return head;
		}
		ListNode *a2 = head->next;
		ListNode *l1 = a1, *l2 = a2;
		ListNode dummy(0);
		dummy.next = head;
		ListNode *pre = &dummy;
		while (l1 && l2){
			a1 = l1;
			a2 = l2;
			l1 = a1->next->next;
			if (l1){
				l2 = a2->next->next;
			}
			a1->next = a2->next;
			a2->next = a1;
			pre->next = a2;
			pre = pre->next->next;
		}
		return dummy.next;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto l = BuildList(vector<int>{1, 2, 3, 4, 5});
	l = s.swapPairs(l);
	PrintList(l);
	system("pause");
	return 0;
}