#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode preHead(0), *p = &preHead;
		int extra = 0;
		while (l1 || l2 || extra) {
			int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
			extra = sum / 10;
			p->next = new ListNode(sum % 10);
			p = p->next;
			l1 = l1 ? l1->next : l1;
			l2 = l2 ? l2->next : l2;
		}
		return preHead.next; // 通过这种方式处理头，可以更加简洁的书写链表
	}

	ListNode* addTwoNumbersMy52ms(ListNode* l1, ListNode* l2) {
		ListNode* ret = new ListNode(0);
		ListNode* cur = ret;
		bool enbit = false;
		int n1 = 0, n2 = 0;
		// it1
		int val = l1->val + l2->val;
		if (enbit){
			val++;
		}
		if (val >= 10){
			val -= 10;
			enbit = true;
		}
		cur->val = val;
		while (l1->next || l2->next){
			if (l1->next){
				l1 = l1->next;
				n1 = l1->val;
			} else{
				n1 = 0;
			}
			if (l2->next){
				l2 = l2->next;
				n2 = l2->val;
			} else{
				n2 = 0;
			}

			int val = n1 + n2;
			if (enbit){
				val++;
				enbit = false;
			}
			if (val >= 10){
				val -= 10;
				enbit = true;
			}

			cur->next = new ListNode(val);
			cur = cur->next;
		}

		if (enbit){
			if (cur){
				cur->next = new ListNode(1);
			} else{
				cur = new ListNode(1);
			}
		}
		return ret;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	s.addTwoNumbers(&ListNode(5), &ListNode(5));
	system("pause");
	return 0;
}