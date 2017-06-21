#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	// 先对字符串进行处理使得其不再含有非法右括号，然后将其翻转以后再检查是否含有非法的左括号．最后左右括号都检查完之后都合法就是我们要的答案了 http://lib.csdn.net/article/datastructure/18481
	vector<string> removeInvalidParentheses(string s) { 
		dfs(s, ')', 0);
		return ans;
	}
private:
	void dfs(string s, char ch, int last){
		for (int i = 0, cnt = 0; i < s.size(); ++i){
			if (s[i] == '(' || s[i] == ')'){
				s[i] == ch ? cnt++ : cnt--; // cnt是要删除括弧的绝对数量
			}
			if (cnt <= 0){
				continue;
			}
			for (int j = last; j <= i; j++){ // 为保证不会产生重复值，需要记录一个最后删除的位置
				if (s[j] == ch && (j == last || s[j - 1] != ch)){ // 注意这里保证不重复的判断
					dfs(s.substr(0,j) + s.substr(j+1), ch, j); 
				}
			}
			return; // 如果在此位置进行过了删除DFS，则没有必要再进行循环
		}
		reverse(s.begin(), s.end());  // 
		if (ch == ')'){
			return dfs(s, '(', 0);
		}
		ans.push_back(s);
	}
	vector<string> ans;
};

int main(int argc, char *argv[]){
	Solution s;
	auto vs = s.removeInvalidParentheses("(a)())()");
	for (auto v : vs){
		cout << v << endl;
	}
	system("pause");
	return 0;
}