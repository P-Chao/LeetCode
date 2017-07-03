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
	ListNode* insertionSortList(ListNode* head) {
		ListNode dummy(0);
		auto form = head;
		while (form){
			auto temp = form->next;
			auto node = &dummy;
			while (node->next){
				if (form->val > node->next->val){
					node = node->next;
				} else{
					break;
				}
			}
			auto tmp = node->next;
			node->next = form;
			form->next = tmp;
			form = temp;
		}
		return dummy.next;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto l = BuildList(vector<int>{2, 3, 5, 2, 1});
	l = s.insertionSortList(l);
	PrintList(l);
	system("pause");
	return 0;
}