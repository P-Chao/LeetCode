#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
	using int64_t = long long;
public:
	vector<string> addOperators(string num, int target) {
		vector<string> result;
		if (num.size() == 0) return result;
		string current;
		current.reserve(num.size() * 2 - 1);
		int64_t n = 0;
		for (int i = 0; i < num.size(); ++i) {
			n = n * 10 + num[i] - '0';
			current += num[i];
			dfs(result, current, 0, n, num, i + 1, target);
			if (n == 0) break;
		}
		return result;
	}
private:
	void dfs(vector<string>& result, string& current, int64_t left, int64_t partial, string& num, int position, int target) {
		if (position == num.size()) {
			if (left + partial == target) result.push_back(current);
			return;
		}
		int64_t n = 0;
		int op_pos = current.size();
		current += '+';
		for (int i = position; i < num.size(); ++i) {
			n = 10 * n + num[i] - '0';
			current += num[i];
			int temp = current.size();
			current[op_pos] = '+';
			dfs(result, current, left + partial, n, num, i + 1, target);
			current.erase(temp);
			current[op_pos] = '-';
			dfs(result, current, left + partial, -n, num, i + 1, target);
			current.erase(temp);
			current[op_pos] = '*';
			dfs(result, current, left, partial * n, num, i + 1, target);
			current.erase(temp);
			if (num[position] == '0') break;
		}
		current.erase(op_pos);
	}
public:
	vector<string> addOperatorsTimeExprensive(string num, int target) {
		tar = target;
		dfs(num, 0, 0, "");
		return res;
	}
private:
	void dfs(string num, long long diff, long long curNum, string out){ // diff Îª³Ë·¨ÐÞÕý
		const int n = num.size();
		if (n == 0 && curNum == tar){
			res.push_back(out);
		}
		for (int i = 1; i <= n; ++i){
			string cur = num.substr(0, i);
			if (cur.size() > 1 && cur[0] == '0'){
				return;
			}
			string next = num.substr(i);
			if (out.size() > 0){
				dfs(next, stoll(cur), curNum + stoll(cur), out + "+" + cur);
				dfs(next, -stoll(cur), curNum - stoll(cur), out + "-" + cur);
				dfs(next, diff * stoll(cur), (curNum - diff) + diff * stoll(cur), out + "*" + cur);
			} else{
				dfs(next, stoll(cur), stoll(cur), cur);
			}
		}
	}
	int tar;
	vector<string> res;
};

int main(int argc, char *argv[]){
	Solution s;
	auto vs = s.addOperators("123", 6);
	for (auto v : vs){
		cout << v << endl;
	}
	system("pause");
	return 0;
}