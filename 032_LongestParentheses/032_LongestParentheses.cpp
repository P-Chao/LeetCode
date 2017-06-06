#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s){
		stack<char> stk;
		stk.push(-1);
		int result = 0;
		for (int i = 0; i < s.size(); ++i){
			if (s[i] == '('){
				stk.push(i);
			} else{
				if (!stk.empty()){
					stk.pop();
				}
				if (!stk.empty()){
					result = max(result, i - stk.top());
				} else{
					stk.push(i);
				}
			}
		}
		return result;
	}

	int longestValidParenthesesMy(string s) { // »¬¶¯´°¿Ú·¨
		const int n = s.size();
		int b = 0, d = 0;
		int l = 0, r = 0;
		int maxlen = 0;
		while (r < n) {
			if (s[r] == '('){
				b++;
			} else{
				d++;
			}

			r++;
			if (b < d){
				l = r;
				b = 0;
				d = 0;
			} else if(b == d){
				if (r - l > maxlen){
					maxlen = r - l;
				}
			}
		}
		
		if (b > d){
			int bound = l;
			b = 0; d = 0;
			l = n - 1; r = n - 1;
			while (bound < l){
				if (s[l] == ')'){
					d++;
				} else{
					b++;
				}

				l--;
				if (b > d){
					r = l;
					b = 0;
					d = 0;
				} else if (b == d){
					if (r - l > maxlen){
						maxlen = r - l;
					}
				}
			}
		}

		return maxlen;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.longestValidParentheses("()(()") << endl;
	system("pause");
	return 0;
}