#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {

	}
};

int main(int argc, char *argv[]){
	Solution s;
	vector<vector<char>> matrix{
		{ '1', '0', '1', '0', '0' },
		{ '1', '0', '1', '1', '1' },
		{ '1', '1', '1', '1', '1' },
		{ '1', '0', '0', '1', '0' } };
	cout << s.maximalSquare(matrix) << endl;
	system("pause");
	return 0;
}