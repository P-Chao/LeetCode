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
	ListNode* reverseKGroup(ListNode* head, int k) {
		auto node = head;
		for (int i = 0; i < k; ++i){
			if (!node){
				return head;
			}
			node = node->next;
		}
		auto new_head = reverseList(head, node); // head 是形参，其地址未改变
		head->next = reverseKGroup(node, k); // 在翻转之后head指向的已经是尾节点了
		return new_head;
	}
private:
	ListNode* reverseList(ListNode *start, ListNode *end){
		ListNode *head = end;
		while (start != end){
			auto tmp = start->next;
			start->next = head;
			head = start;
			start = tmp;
		}
		return head;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto l = BuildList(vector<int>{1, 2, 3, 4, 5});
	l = s.reverseKGroup(l, 3);
	PrintList(l);
	system("pause");
	return 0;
}