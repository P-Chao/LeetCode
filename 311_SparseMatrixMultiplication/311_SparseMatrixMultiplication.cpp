#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
		const int n1 = A.size(), n2 = B.size(), n3 = B[0].size();
		vector<vector<int>> C(n1, vector<int>(n3, 0));
		for (int i = 0; i < n1; ++i){
			for (int j = 0; j < n2; ++j){
				if (A[i][j]){
					for (int k = 0; k < n3; ++k){
						C[i][k] += A[i][j] * B[j][k];
					}
				}
			}
		}
		return C;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	vector<vector<int>> A{
		{ 1, 0, 0 },
		{ -1, 0, 3 } };
	vector<vector<int>> B{
		{ 7, 0, 0 },
		{ 0, 0, 0 },
		{ 0, 0, 1 } };
	auto mat = s.multiply(A, A);
	for (auto line : mat){
		for (auto v : line){
			cout << v << ", ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}