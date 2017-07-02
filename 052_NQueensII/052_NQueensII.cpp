#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int totalNQueens(int n) {
		vector<bool> maskc(n, true); // j = 0:n-1
		vector<bool> maskl(2*n-1, true); // i + j = 0:2n-2
		vector<bool> maskr(2*n-1, true); // i - j + n - 1 = 0:2n-2
		nn = n;
		cnt = 0;
		dfs(0, maskc, maskl, maskr);
		return cnt;
	}

private:
	void dfs(int i, vector<bool>& maskc, vector<bool>& maskl, vector<bool>& maskr){
		if (i == nn){
			cnt++;
		}
		for (int j = 0; j < nn; ++j){
			if (maskc[j] && maskl[i+j] && maskr[i-j+nn-1]){
				maskc[j] = false;
				maskl[i+j] = false;
				maskr[i-j+nn-1] = false;
				dfs(i + 1, maskc, maskl, maskr);
				maskc[j] = true;
				maskl[i+j] = true;
				maskr[i-j+nn-1] = true;
			}
		}
	}
	int nn, cnt;
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.totalNQueens(8) << endl;
	system("pause");
	return 0;
}