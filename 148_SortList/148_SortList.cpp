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
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next){
			return head;
		}
		return mergeSort(head);
	}
private:
	ListNode* mergeSort(ListNode *head){
		if (!head){
			return head;
		}
		ListNode *fast = head, *slow = head, *prev = head;
		while (fast && fast->next) {
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		if (fast == slow){
			return head;
		}
		prev->next = NULL;
		auto left = mergeSort(head);
		auto right = mergeSort(slow);
		return merge(left, right);
	}

	ListNode* merge(ListNode *left, ListNode *right){
		ListNode dummy(0);
		auto node = &dummy;
		if (!left){
			return right;
		}
		if (!right){
			return left;
		}
		while (left && right){
			auto ltmp = left->next;
			auto rtmp = right->next;
			if (left->val < right->val){
				node->next = left;
				node = node->next;
				left = ltmp;
				if (!left){
					node->next = right;
				}
			} else{
				node->next = right;
				node = node->next;
				right = rtmp;
				if (!right){
					node->next = left;
				}
			}
		}
		return dummy.next;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto l = BuildList(vector<int>{2, 3, 5, 2, 1});
	l = s.sortList(l);
	PrintList(l);
	system("pause");
	return 0;
}