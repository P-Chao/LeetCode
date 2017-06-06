#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		int N1 = num1.size();
		int N2 = num2.size();
		if (N1 == 0 || N2 == 0) return "";

		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		string ret(N1 + N2, '0');

		for (int i = 0; i<N1; i++) {
			int carry = 0;
			int val = num1[i] - '0';
			for (int j = 0; j<N2; j++) {
				carry += val * (num2[j] - '0') + (ret[i + j] - '0');
				ret[i + j] = carry % 10 + '0';
				carry = carry / 10;
			}
			if (carry != 0)
				ret[i + N2] = carry + '0';
		}

		reverse(ret.begin(), ret.end());

		int count = 0;
		while (count<(N1 + N2 - 1) && ret[count] == '0') {
			count++;
		}
		ret.erase(0, count);

		return ret;
	}

	string multiplyMy(string num1, string num2) {
		const int n1 = num1.size();
		const int n2 = num2.size();
		if (n1 == 0 || n2 == 0){
			return string("");
		}
		string res = "0";
		string pot = "";
		for (int i = n2 - 1; i >= 0; --i){
			string tmp;
			tmp = mpy(num1, num2[i]);
			tmp = tmp + pot;
			res = add(res, tmp);
			pot += "0";
		}
		return res;
	}

private:
	string mpy(string num, char s){
		string res;
		const int n = num.size();
		int t = s - '0';
		if (t == 0){
			return string("0");
		}
		int en = 0;
		char str[] = "0";
		for (int i = n - 1; i >= 0; --i){
			int tmp = num[i] - '0';
			tmp = tmp * t + en;
			en = tmp / 10;
			str[0] = tmp % 10 + '0';
			res = string(str) + res;
		}
		if (en){
			str[0] = en + '0';
			res = string(str) + res;
		}
		return res;
	}

	string add(string& num1, string& num2){
		const int n1 = num1.size();
		const int n2 = num2.size();
		int i = n1, j = n2;
		int k = 0;
		string res;
		char str[] = "0";
		while (i > 0 || j > 0) {
			i--;
			j--;
			if (i >= 0){
				k += (num1[i] - '0');
			}
			if (j >= 0){
				k += (num2[j] - '0');
			}
			str[0] = (k % 10 + '0');
			res = string(str) + res;
			k = k / 10;
		}
		if (k){
			str[0] = (k + '0');
			res = string(str) + res;
		}
		res = res.erase(0, res.find_first_not_of("0"));
		if (res.empty()){
			return string("0");
		}
		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.multiply("0", "52") << endl;
	system("pause");
	return 0;
}