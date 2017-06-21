#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string removeDuplicateLetters(string s) {
		int ahead[256] = {};
		bool inresult[256] = {}; // 对应字符是否出现在result中
		for (auto c : s){
			ahead[c]++;
		}
		string result = " ";
		for (auto c : s) {
			ahead[c]--;
			if (inresult[c]){ // 如果该词出现在结果中，则说明其已经被放置在正确的位置上
				continue;
			}
			while (c < result.back() && ahead[result.back()]) { // 如果result最后一个字母对c违规，则不断将其删除，直到c放置正确
				inresult[result.back()] = false; // 这个while循环体现了贪心
				result.pop_back();
			}
			result += c;
			inresult[c] = true;
		}
		return result.substr(1);
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.removeDuplicateLetters("cbacdcbc") << endl;
	system("pause");
	return 0;
}