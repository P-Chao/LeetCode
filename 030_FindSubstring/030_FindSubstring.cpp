#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		map<string, int> traits;
		if (s.empty() || words.empty()){
			return res;
		}

		for (auto word : words){
			traits[word]++;
		}
		int len = words[0].size();

		for (int i = 0; i < len; ++i){ // 相当于余数遍历，第二级循环就不需要逐个遍历了，整体法： 0,1,2 枚举过之后，就不用枚举3了
			map<string, int> window;

			int l = i; // left \ right 两指针指向左右两边界
			int r = i; 
			while (r < s.size()){ // 右起始边界右移
				while (r < s.size()){ // 拓展窗口
					auto word = s.substr(r, len);
					r += len;
					if (traits.find(word) == traits.end()){  // 没找到，那么窗口右移len
						window.clear();
						l = r;
					} else{ // 找到了
						window[word]++;
						if (window[word] >= traits[word]){
							break;
						}
					}
				}
				while (l < r){  // 收缩窗口，在尾部的单词多了，因为上一个while是因为尾部的单词多出才break的
					auto head = s.substr(l, len); // 最左的字符串
					auto tail = s.substr(r - len, len);  // 最右的字符串
					if (window[tail] == traits[tail]){
						break;
					}
					l += len;
					window[head]--;
				} // 检查解
				if ((r - l) == len * words.size()){
					res.push_back(l);
				}
			}
		}
		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	vector<string> vstr = {"foo" , "bar"};
	auto vv = s.findSubstring("barfoobarfoobar", vstr);
	for (auto v : vv){
		cout << v << ", ";
	}
	system("pause");
	return 0;
}
