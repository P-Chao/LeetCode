#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int xs = max(A, E);
		int xe = min(C, G);
		int ys = max(B, F);
		int ye = min(D, H);
		int overlap = 0;
		if (xs < xe && ys < ye){
			overlap = (xe - xs) * (ye - ys);
		}
		return (C - A)*(D - B) + (G - E)*(H - F) - overlap;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
	system("pause");
	return 0;
}