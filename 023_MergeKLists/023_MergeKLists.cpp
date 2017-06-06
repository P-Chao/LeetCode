#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* BuildList(vector<int>& nums){
	ListNode dummy = ListNode(0);
	ListNode *head = &dummy;
	for (auto v : nums){
		head->next = new ListNode(v);
		head = head->next;
	}
	return dummy.next;
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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode *, vector<ListNode*>, cmp> q;
		for (auto l : lists){
			if (l){
				q.push(l);
			}
		}
		if (q.empty()){
			return NULL;
		}

		ListNode dummy(0);
		ListNode* node = &dummy;
		while (!q.empty()){
			node->next = q.top();
			q.pop();
			node = node->next;
			if (node->next){
				q.push(node->next);
			}
		}
		return dummy.next;
	}
	
private:
	struct cmp{
		bool operator()(const ListNode* l, const ListNode* r){
			return l->val > r->val;
		}
	};
};

int main(int argc, char *argv){
	Solution s;
	system("pause");
	return 0;
}