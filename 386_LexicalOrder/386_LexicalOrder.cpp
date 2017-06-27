#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> lexicalOrder(int n) {
		vector<int> res(n);
		int cur = 1;
		for (int i = 0; i < n; ++i){
			res[i] = cur;
			if (cur * 10 <= n){
				cur *= 10;
			} else{
				if (cur >= n){
					cur /= 10;
				}
				cur += 1;
				while (cur % 10 == 0) {
					cur /= 10;
				}
			}
		}
		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto vs = s.lexicalOrder(13);
	for (auto v : vs){
		cout << v << ", ";
	}
	system("pause");
	return 0;
}