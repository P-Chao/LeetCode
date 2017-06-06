#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	void reverseWords(string &s) { // 两次翻转法, 考察去除多余的空格
		const int n = s.size();
		if (n == 0){
			return;
		}
		int left = 0, right = 0, i = 0;
		while (i < n){
			while (i < n && s[i] == ' '){
				i++;
			}
			if (i >= n){
				break;
			}
			if (left != right){
				s[right++] = ' ';
			}
			left = right;
			while (i < n && s[i] != ' '){
				s[right++] = s[i++]; // 平移去除头部空格
			}
			reverse(s.begin() + left, s.begin() + right); // 执行翻转
		}
		s.resize(right);
		reverse(s.begin(), s.end());
		return;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	string str(" the sky  is blue ");
	s.reverseWords(str);
	cout << str << endl;
	system("pause");
	return 0;
}