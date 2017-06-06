#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		const int n = s.size();
		if (n % 2 == 1){
			return false;
		} else if (n == 0){
			return true;
		}

		stack<char> stk;
		for (int i = 0; i < n; ++i){
			switch (s[i]){
			case '(':
			case '{':
			case '[':
				stk.push(s[i]);
				break;
			case ')':
				if (stk.empty()){
					return false;
				}
				if (stk.top() != '('){
					return false;
				} else{
					stk.pop();
				}
				break;
			case '}':
				if (stk.empty()){
					return false;
				}
				if (stk.top() != '{'){
					return false;
				} else{
					stk.pop();
				}
				break;
			case ']':
				if (stk.empty()){
					return false;
				}
				if (stk.top() != '['){
					return false;
				} else{
					stk.pop();
				}
				break;
			default:
				return false;
			}
		}
		return stk.empty();
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.isValid("([)]") << endl;
	system("pause");
	return 0;
}