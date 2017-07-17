#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB){
			return NULL;
		}
		ListNode *nodeA = headA, *nodeB = headB;
		int na = 1, nb = 1;
		while (nodeA->next){
			nodeA = nodeA->next;
			++na;
		}
		while (nodeB->next){
			nodeB = nodeB->next;
			++nb;
		}
		if (nodeA != nodeB){
			return NULL;
		}
		nodeA = headA;
		nodeB = headB;
		while (nodeA != nodeB){
			if (na > nb){
				na--;
				nodeA = nodeA->next;
			} else if(na < nb){
				nb--;
				nodeB = nodeB->next;
			} else{
				na--;
				nb--;
				nodeA = nodeA->next;
				nodeB = nodeB->next;
			}
		}
		return nodeA;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto l = s.getIntersectionNode(NULL, NULL);
	cout << l->val << endl;
	system("pause");
	return 0;
}