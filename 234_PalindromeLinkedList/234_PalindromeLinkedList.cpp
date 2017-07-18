#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next){
			return true;
		}
		ListNode *hd = NULL;;
		ListNode *slow = head, *fast = head;
		while (fast && fast->next){
			fast = fast->next->next;
			auto ts = slow->next;
			slow->next = hd;
			hd = slow;
			slow = ts;
		}
		if (fast){
			slow = slow->next;
		}
		while (slow && hd){
			if (slow->val == hd->val){
				slow = slow->next;
				hd = hd->next;
			} else{
				return false;
			}
		}
		return true;
	}
};

int main(int argc, char* argv[]){
	Solution s;
	cout << s.isPalindrome(NULL) << endl;
	system("pause");
	return 0;
}