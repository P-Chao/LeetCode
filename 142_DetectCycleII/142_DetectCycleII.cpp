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
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL || head->next == head){
			return head;
		}
		ListNode *fast = head, *slow = head;
		while (fast != NULL && fast->next != NULL){
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow){
				break;
			}
		}
		if (fast == NULL || fast->next == NULL){
			return NULL;
		}
		while (head != slow){
			head = head->next;
			slow = slow->next;
		}
		return head;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto l = BuildList(vector<int>{1, 2, 3, 4, 5});
	l = s.detectCycle(l);
	PrintList(l);
	system("pause");
	return 0;
}