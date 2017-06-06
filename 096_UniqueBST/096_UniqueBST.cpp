#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numTrees(int n) {
		if (n < 2){
			return 1;
		}
		vector<int> cnt(n+1, 0);
		cnt[1] = cnt[0] = 1;
		for (int i = 2; i <= n; ++i){
			for (int j = 0; j < i; ++j){
				cnt[i] += cnt[i-1-j] * cnt[j];
			}
		}
		return cnt[n];
	}
};

int main(int argc, char *argv){
	Solution s;
	cout << s.numTrees(3) << endl;
	system("pause");
	return 0;
}