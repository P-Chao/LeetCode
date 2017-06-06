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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m >= n){
			return head;
		}
		ListNode dummy(0);
		dummy.next = head;
		ListNode *node = &dummy;
		ListNode *nh = NULL, *start = NULL, *end = NULL;
		int len = 0;
		while (node->next){
			auto pre = node;
			node = node->next;
			len++;
			while (len >= m && len <= n){
				if (len == m){
					start = node;
				}
				auto tmp = node->next;
				node->next = nh;
				nh = node;
				node = tmp;
				len++;
			}
			if (len == n + 1){
				pre->next = nh;
				start->next = node;
				break;
			}
		}
		return dummy.next;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto l = BuildList(vector<int>{1, 2, 3, 4, 5});
	l = s.reverseBetween(l, 2, 4);
	PrintList(l);
	system("pause");
	return 0;
}