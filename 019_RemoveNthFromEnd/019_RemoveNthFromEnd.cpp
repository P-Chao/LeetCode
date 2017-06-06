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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* cur = new ListNode(0);
		ListNode* h = cur;
		cur->next = head;
		ListNode* nth = cur;
		int len = 0;
		while (cur->next){
			len++;
			cur = cur->next;
			if (len > n){
				nth = nth->next;
			}
		} // nth->next 就是我们要删除的
		if (n > len){ // 不删除
			return head;
		}
		if (nth->next){ // 如果nth不是最后一个元素
			nth->next = nth->next->next;
		}
		return h->next;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto list = BuildList(vector<int>{1, 2});
	ListNode *nd = s.removeNthFromEnd(list, 1);
	PrintList(nd);
	system("pause");
	return 0;
}
