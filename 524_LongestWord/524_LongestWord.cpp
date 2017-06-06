/*
LeetCode 524
Peng Chao, 3,Apr
Line: 148
*/

#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

class Solution_ {
public:
	static bool compare(const string& a, const string& b){
		return a.length() > b.length();
	}

	bool iscomp(string& s, string& d){
		const int slen = s.length(), dlen = d.length();
		int i = 0, j = 0;
		if (dlen > slen){
			return false;
		}
		for (i = 0; i < dlen;){
			if (s[j] == d[i]){
				i++;
				j++;
				if (i == dlen){
					return true;
				}
			}
			else{
				j++;
			}
			if (j == slen){
				return false;
			}

		}
		return false;
	}

	string findLongestWord(string s, vector<string>& d) {
		if (s == "")
			return string("");

		sort(d.begin(), d.end());
		stable_sort(d.begin(), d.end(), compare);

		const int dsz = d.size();
		for (int j = 0; j < dsz; ++j){
			if (iscomp(s, d[j])){
				return d[j];
			}
		}

		return string("");
	}
};

class Solution {
public:
	typedef struct _LenMap{
		int len;
		int id;
		bool operator>(const _LenMap& l) const{
			return this->len > l.len;
		}
		bool operator<(const _LenMap& l) const{
			return this->len < l.len;
		}
		bool operator==(const _LenMap& l) const{
			return this->len == l.len;
		}
	} LenMap;

	bool iscomp(string& s, string& d){
		const int slen = s.length(), dlen = d.length();
		int i = 0, j = 0;
		if (dlen > slen){
			return false;
		}
		for (i = 0; i < dlen;){
			if (s[j] == d[i]){
				i++;
				j++;
				if (i == dlen){
					return true;
				}
			} else{
				j++;
			}
			if (j == slen){
				return false;
			}
			
		}
		return false;
	}

	string findLongestWord(string s, vector<string>& d) {
		if (s == "")
			return string("");
		const int dsz = d.size();
		
		vector<LenMap> m;
		m.resize(d.size());

		sort(d.begin(), d.end());
		for (int j = 0; j < dsz; ++j){
			m[j].id = j;
			m[j].len = d[j].length();
		}

		stable_sort(m.begin(), m.end(), greater<LenMap>());
		vector<string> sorted_d(dsz);
		for (int j = 0; j < dsz; ++j){
			sorted_d[j] = d[m[j].id];
			if (iscomp(s, sorted_d[j])){
				return sorted_d[j];
			}
		}

		return string("");
	}
};

int main(int argc, char *argv[]){
	//"abpcplea"
	//["ale", "apple", "monkey", "plea"]
	vector<string> dic;
	dic.push_back("ale");
	dic.push_back("apple");
	dic.push_back("monkey");
	dic.push_back("plea");
	string str("abpcplea");

	Solution s;
	cout << s.findLongestWord(str, dic);

	system("pause");
	return 0;
}
