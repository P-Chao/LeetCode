#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		const int m = a.size();
		const int n = b.size();
		if (m == 0){
			return b;
		}
		if (n == 0){
			return a;
		}

		int i = m, j = n;
		string res;

		char enbit = 0;
		while (i > 0 || j > 0){
			i--;
			j--;
			int k = 0;
			if (enbit){
				k++;
			}
			if (i >= 0 && a[i] == '1'){
				k++;
			}
			if (j >= 0 && b[j] == '1'){
				k++;
			}
			enbit = (k / 2);
			if (k % 2){
				res += '1';
			} else{
				res += '0';
			}
		}
		if (enbit){
			res += '1';
		}
		reverse(res.begin(), res.end());
		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.addBinary("00111", "1000000") << endl;
	system("pause");
	return 0;
}