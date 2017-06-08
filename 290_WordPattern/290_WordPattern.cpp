#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		const int n = pattern.size();
		const int m = str.size();
		unordered_map<char, vector<int>> hash;
		for (int i = 0; i < n; ++i){
			hash[pattern[i]].push_back(i);
		}
		int prev = 0;
		vector<string> vstr;
		for (int i = 0; i < m; ++i){
			if (str[i] == ' '){
				vstr.push_back(str.substr(prev, i - prev));
				prev = i + 1;
			}
		}
		if (prev != m){
			vstr.push_back(str.substr(prev, m - prev));
		}

		if (vstr.size() != n){
			return false;
		}
		
		unordered_set<string> once;
		for (auto h : hash){
			string s = vstr[h.second[0]];
			if (once.count(s) == 1){
				return false;
			} else{
				once.insert(s);
			}
			for (auto m : h.second){
				if (s != vstr[m]){
					return false;
				}
				
			}
		}
		return true;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.wordPattern("abbba", "dog cat cat ddog") << endl;
	system("pause");
	return 0;
}
