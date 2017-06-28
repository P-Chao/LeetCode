#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string decodeString(string s) {
		int k = 0;
		return dfs(s, k);
	}
private:
	string dfs(string s, int &k){
		string ans;
		int cnt = 0;
		while (k < s.size()){
			if (isdigit(s[k])){
				cnt = cnt * 10 + (s[k++]-'0');
			} else if (s[k] == '['){
				string tem = dfs(s, ++k);
				for (int i = 0; i < cnt; ++i){
					ans += tem;
				}
				cnt = 0;
			} else if (s[k] == ']'){
				k++;
				return ans;
			} else{
				ans += s[k++];
			}
		}
		return ans;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.decodeString("3[a]2[bc]") << endl;
	system("pause");
	return 0;
}