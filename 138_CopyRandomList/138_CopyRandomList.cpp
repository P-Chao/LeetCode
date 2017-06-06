#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		RandomListNode dummy(0), dummyc(0);
		dummy.next = head;
		RandomListNode *copy = &dummyc;
		RandomListNode *node = &dummy;
		unordered_map<RandomListNode*, RandomListNode*> hash;
		
		while (node->next){
			node = node->next;
			copy->next = new RandomListNode(node->label);
			copy = copy->next;
			hash.insert({ node, copy });
		}
		
		copy = &dummyc;
		node = &dummy;

		while (copy->next){
			copy = copy->next;
			node = node->next;
			copy->random = hash[node->random];
		}

		return dummyc.next;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	system("pause");
	return 0;
}