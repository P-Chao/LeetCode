/*
LeetCode 274
Peng Chao, 3,Apr
Line: 70
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int hIndex_old(vector<int>& citations) {
		sort(citations.rbegin(), citations.rend());
		const int len = citations.size();
		if (len == 0){
			return 0;
		}
		for (int i = 0; i < len; ++i){
			if (citations[i] < i+1){
				return i;
			}
		}
		return len;
	}

	int hIndex(vector<int>& citations){
		const int len = citations.size();
		if (len == 0){
			return 0;
		}

		vector<int> count(len+1);
		for (int i = 0; i < len; ++i){
			if (citations[i] >= len){
				count[len]++;
			}
			else if (citations[i] >= 0){
				count[citations[i]]++;
			}
			else{ //ciatations[i] < 0
				count[0]++; // report error;
			}
		}
		int total_cite = 0;
		for (int i = len; i >= 0; --i){
			total_cite += count[i];
			if (total_cite >= i){
				return i;
			}
		}
		return 0;
	}
};

int main(int argc, char *argv[]){
	int a[] = {0, 0};
	vector<int> v(a, a+2), vv;
	vv.push_back(1);

	Solution s;
	cout << s.hIndex(v) << endl;

	system("pause");
	return 0;
}
