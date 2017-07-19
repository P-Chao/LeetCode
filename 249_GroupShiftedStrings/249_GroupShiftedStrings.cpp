#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<vector<string>> groupStrings(vector<string>& strings) {
		const int n = strings.size();
		vector<vector<string>> res;
		unordered_map<string, vector<string>> buckets;
		for (auto str : strings){
			auto strs = str;
			if (str.empty()){
				continue;
			}
			for (int i = 0; i < strs.size(); ++i){
				strs[i] -= str[0];
				if (strs[i] < 0){
					strs[i] += 26;
				}
			}
			buckets[strs].push_back(str);
		}
		for (auto vs : buckets){
			res.push_back(vs.second);
		}
		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto res = s.groupStrings(vector<string>{"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"});
	for (auto vs : res){
		for (auto v : vs){
			cout << v << ", ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}