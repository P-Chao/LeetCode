#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		const int n = s.size();
		if (n < 9){
			return{};
		}
		string ss = s;
		char mp[26] = { 0 };
		mp['C' - 'A'] = 1;
		mp['G' - 'A'] = 2;
		mp['T' - 'A'] = 3;
		for (auto& ch : ss){
			ch = mp[ch - 'A'];
		}

		int q = 0;
		vector<string> res;
		unordered_map<int, int> hash;
		for (int i = 0; i < n; ++i){
			q = (((q << 2) & 0x000fffff) | ss[i]);
			if (i >= 9){
				hash[q]++;
				if (hash[q] == 2){
					res.push_back(s.substr(i-9, 10));
				}
			}
		}
		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto vs = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	for (auto v : vs){
		cout << v << endl;
	}
	system("pause");
	return 0;
}