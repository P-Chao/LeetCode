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
	ListNode* rotateRight(ListNode* head, int k) {
		FLAG:
		ListNode dummy(0);
		dummy.next = head;
		ListNode *node1 = &dummy;
		ListNode *node2 = &dummy;
		int len = 0;
		while (node1->next){
			node1 = node1->next;
			len++;
			if (len - k > 0){
				node2 = node2->next;
			}
		}
		if (node1 == node2){
			return head;
		}
		if (k >= len){
			k = k%len;
			goto FLAG;
		}
		auto tmp = node2->next;
		node1->next = head;
		node2->next = NULL;
		return tmp;
	}

	ListNode* rotateRightNoGoto(ListNode* head, int k) {
		if (!head) return head;

		int len = 1; // number of nodes
		ListNode *newH, *tail;
		newH = tail = head;

		while (tail->next){  // get the number of nodes in the list
			tail = tail->next;
			len++;
		}
		tail->next = head; // circle the link

		if (k %= len){
			for (auto i = 0; i<len - k; i++) 
				tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
		}
		newH = tail->next;
		tail->next = NULL;
		return newH;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto l = BuildList(vector<int>{1, 2, 3, 4, 5});
	l = s.rotateRight(l, 7);
	PrintList(l);
	system("pause");
	return 0;
}