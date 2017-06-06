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
	ListNode* partition(ListNode* head, int x) {
		ListNode dummy(0);
		ListNode dummytail(0);
		dummy.next = head;
		ListNode* node = &dummy;
		ListNode* tail = &dummytail;
		while (node->next){
			auto pre = node;
			node = node->next;
			if (node->val >= x){
				pre->next = node->next;
				tail->next = node;
				tail = tail->next;
				node = pre;
			}
		}
		tail->next = NULL;
		node->next = dummytail.next;
		return dummy.next;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto l = BuildList(vector<int>{1, 4, 3, 2, 5, 2});
	l = s.partition(l, 3);
	PrintList(l);
	system("pause");
	return 0;
}