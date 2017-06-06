#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int strStr(char *haystack, char *needle) {  // KMP
		int hlen = strlen(haystack);
		int nlen = strlen(needle);
		int* next = new int[nlen];
		getNext(needle, next);
		int i = 0;
		int j = 0;
		while (i < hlen && j < nlen)
		{
			if (j == -1 || haystack[i] == needle[j])
			{// match current position, go next
				i++;
				j++;
			}
			else
			{// jump to the previous position to try matching
				j = next[j];
			}
		}
		if (j == nlen)
			// all match
			return i - nlen;
		else
			return -1;
	}
	void getNext(char *needle, int next[])
	{// self match to contruct next array
		int nlen = strlen(needle);
		int j = -1;     // slow pointer
		int i = 0;      // fast pointer
		next[i] = -1;    //init next has one element
		while (i < nlen - 1)
		{
			if (j == -1 || needle[i] == needle[j])
			{
				j++;
				i++;           //thus the condition (i < nlen-1)
				next[i] = j;    //if position i not match, jump to position j
			}
			else
			{
				j = next[j];    //jump to the previous position to try matching
			}
		}
	}


	int strStrMy(string haystack, string needle) {
		const int n1 = haystack.size();
		const int n2 = needle.size();
		if (n2 == 0){
			return 0;
		}
		if (n1 < n2){
			return -1;
		}
		for (int i = 0; i <= n1 - n2; ++i){
			bool flag = true;
			for (int j = 0; j < n2; ++j){
				if (haystack[i + j] != needle[j]){
					flag = false;
					break;
				}
			}
			if (flag){
				return i;
			}
		}
		return -1;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.strStr("a", "a") << endl;
	system("pause");
	return 0;
}