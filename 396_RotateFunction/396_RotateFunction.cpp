#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxRotateFunction(vector<int>& A) {
		const int n = A.size();
		if (n == 0){
			return 0;
		}
		long long sum = 0, fval = 0, fmax = 0;
		for (int i = 0; i < n; ++i){
			sum += A[i];
			fval += i * A[i];
		}
		fmax = fval;
		for (int i = n-1; i > 0; --i){
			fval += sum;
			fval -= n*A[i];
			fmax = max(fmax, fval);
		}
		return fmax;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.maxRotateFunction(vector<int>{4, 3, 2, 6}) << endl;
	system("pause");
	return 0;
}