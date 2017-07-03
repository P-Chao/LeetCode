#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <algorithm>

using namespace std;

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		vector<string> strs;
		stringstream ss;
		string str;
		for (auto num : nums){
			ss.clear();
			ss << num;
			ss >> str;
			strs.push_back(str);
		}
		auto cmp = [](const string &lhs, const string &rhs)->bool{
			return lhs + rhs > rhs + lhs; // Important
		};
		sort(strs.begin(), strs.end(), cmp);
		str.clear();
		for (auto s : strs){
			str += s;
		}
		str.erase(0, str.find_first_not_of("0"));
		if (!str.length()){
			str = "0";
		}
		return str;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.largestNumber(vector<int>{3, 30, 34, 5, 9}) << endl;
	system("pause");
	return 0;
}