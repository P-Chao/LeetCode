#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.length() != t.length()) return false;

		vector<char> s2t(256, '\0');
		vector<char> t2s(256, '\0');
		for (int i = 0; i < s.length(); i++) {
			if (s2t[s[i]] != '\0' && s2t[s[i]] != t[i]) return false;
			if (t2s[t[i]] != '\0' && t2s[t[i]] != s[i]) return false;
			s2t[s[i]] = t[i];
			t2s[t[i]] = s[i];
		}

		return true;
	}

	bool isIsomorphicMy(string s, string t) {
		const int n = s.size();
		if (n != t.size()){
			return false;
		}
		unordered_map<char, int> ms, mt;
		int label = 0;
		for (int i = 0; i < n; ++i){
			int slabel = 0, tlabel = 0;
			if (ms.find(s[i]) == ms.end()){
				ms[s[i]] = label;
				slabel = label;
			} else{
				slabel = ms[s[i]];
			}

			if (mt.find(t[i]) == mt.end()){
				mt[t[i]] = label;
				tlabel = label;
				label++;
			} else{
				tlabel = mt[t[i]];
			}
			
			if (slabel != tlabel){
				return false;
			}
		}
		return true;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.isIsomorphic("abb", "abb") << endl;
	system("pause");
	return 0;
}