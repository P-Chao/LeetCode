#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		unordered_multimap<string, string> hmp;
		for (auto str : strs){
			auto sstr = str;
			sort(sstr.begin(), sstr.end());
			hmp.insert({ sstr, str });
		}

		for (auto iter = hmp.begin(); iter != hmp.end(); /*iter = hmp.upper_bound(iter->first)*/){
			auto r = hmp.equal_range(iter->first);
			vector<string> ans;
			for (auto i = r.first; i != r.second; ++i){
				ans.push_back(i->second);
			}
			res.push_back(ans);
			iter = r.second;
		}

		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto vvs = s.groupAnagrams(vector<string>{"eat", "tea", "tan", "ate", "nat", "bat"});
	for (auto vs : vvs){
		for (auto s : vs){
			cout << s << ", ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
