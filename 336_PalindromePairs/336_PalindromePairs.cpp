#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		vector<vector<int>> ans;
		unordered_map<string, int> dic;
		int sz = words.size();
		for (int i = 0; i < sz; ++i){
			dic[words[i]] = i;
		}
		for (int i = 0; i < sz; ++i){
			int len = words[i].length();
			dic.erase(words[i]);
			for (int j = 0; j <= len; ++j){
				string subL = words[i].substr(0, j);
				string subR = words[i].substr(j);
				string revL, revR;
				revL = revL.assign(subL.rbegin(), subL.rend());
				revR = revR.assign(subR.rbegin(), subR.rend());
				if (j != len && isvalid(subR) && dic.count(revL)){ // 将左半部分翻转，放在右边
					ans.push_back({i, dic[revL]});
				}
				if (isvalid(subL) && dic.count(revR)){ // 将右半部分翻转，放在左边
					ans.push_back({dic[revR], i});
				}
			}
			dic[words[i]] = i;
		}
		return ans;
	}
private:
	bool isvalid(string s){
		int i = 0, j = s.size() - 1;
		while (i <= j){
			if (s[i++] != s[j--]){
				return false;
			}
		}
		return true;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto matrix = s.palindromePairs(vector<string>{"abcd", "dcba", "lls", "s", "sssll"});
	for (auto line : matrix){
		for (auto v : line){
			cout << v << ", ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}