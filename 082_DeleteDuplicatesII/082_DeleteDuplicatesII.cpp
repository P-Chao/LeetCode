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
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode dummy(INT_MAX);
		dummy.next = head;
		ListNode *node = &dummy;
		ListNode *tail = &dummy;
		while (tail->next){
			ListNode *start = tail, *end = tail;
			while (end->next && end->val == end->next->val){
				end = end->next;
			}
			if (start != end){ // É¾³ýÖØ¸´½Úµã
				if (end->next){
					start->val = end->next->val;
					start->next = end->next->next;
				} else{
					ListNode *tmp = &dummy;
					while (tmp->next != start){
						tmp = tmp->next;
					}
					tmp->next = NULL;
					break;
				}
			} else{
				if (end->next){
					tail = end->next;
				}
			}
			
		}
		return dummy.next;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto l = BuildList(vector<int>{1, 1, 2, 3, 3, 4, 4, 4, 5, 5});
	l = s.deleteDuplicates(l);
	PrintList(l);
	system("pause");
	return 0;
}