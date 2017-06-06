#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Counter{
	int ct;		//count
	char ch;	//chapter
	bool operator>(const Counter& th){
		return ct > th.ct;
	}
	bool operator==(const Counter& th){
		return ct == th.ct;
	}
	bool operator<(const Counter& th){
		return ct < th.ct;
	}
};

class Solution {
public:
	string frequencySort(string s) {
		string result;
		vector<Counter> c(128);
		
		for (int i = 0; i < c.size(); ++i){
			c[i].ct = 0;
			c[i].ch = i;
		}
		for (auto ch : s){
			c[ch].ct++;
		}
		sort(c.rbegin(), c.rend());
		for (int i = 0; i < c.size(); ++i){
			while (c[i].ct > 0){
				result += c[i].ch;
				c[i].ct--;
			}
		}
		return result;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.frequencySort(string("ZZccaaz"));
	system("pause");
	return 0;
}