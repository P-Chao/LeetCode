#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		int r1 = 0, r2 = 0;
		stack<int> stk;
		for (auto ops : tokens){
			if (ops == "+"){
				r1 = stk.top(); stk.pop();
				r2 = stk.top(); stk.pop();
				stk.push(r2 + r1);
			}
			else if (ops == "-"){
				r1 = stk.top(); stk.pop();
				r2 = stk.top(); stk.pop();
				stk.push(r2 - r1);
			}
			else if (ops == "*"){
				r1 = stk.top(); stk.pop();
				r2 = stk.top(); stk.pop();
				stk.push(r2 * r1);
			}
			else if (ops == "/"){
				r1 = stk.top(); stk.pop();
				r2 = stk.top(); stk.pop();
				if (r1 == 0){
					stk.push(INT_MAX);
				} else{
					stk.push(r2 / r1);
				}
			}
			else{
				stk.push(atoi(ops.c_str()));
			}
		}
		return stk.top();
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.evalRPN(vector<string>{"18"}) << endl;
	system("pause");
	return 0;
}