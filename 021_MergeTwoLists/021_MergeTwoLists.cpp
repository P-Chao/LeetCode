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
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode dummy(INT_MIN);
		ListNode *tail = &dummy;

		while (l1 && l2) {
			if (l1->val < l2->val) {
				tail->next = l1;
				l1 = l1->next;
			} else {
				tail->next = l2;
				l2 = l2->next;
			}
			tail = tail->next;
		}

		tail->next = l1 ? l1 : l2;
		return dummy.next;
	}

	ListNode* mergeTwoListsMy(ListNode* l1, ListNode* l2) {
		ListNode *head = new ListNode(INT_MIN);
		head->next = l1;
		ListNode *a1 = head, *a2 = l2;
		if (!l1){
			return l2;
		}
		if (!l2){
			return l1;
		}
		while (true){
			if (a1->val <= a2->val){
				if (a1->next){
					a1 = a1->next;
				} else{
					a1->next = a2;
					break;
				}
			} else{
				ListNode *t1 = a1->next;
				ListNode *t2 = a2;
				swap(a1->val, a2->val);
				a2 = a2->next;
				// µ÷ÕûÖ¸Õë
				a1->next = t2;
				t2->next = t1;
				if (!a2){
					break;
				}
			}
		}
		return head->next;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	ListNode *l1 = BuildList(vector<int>{2});
	ListNode *l2 = BuildList(vector<int>{1});
	auto l = s.mergeTwoLists(l1, l2);
	PrintList(l);
	system("pause");
	return 0;
}