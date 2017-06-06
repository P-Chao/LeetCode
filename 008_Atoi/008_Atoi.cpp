#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
	int myAtoi(string str){
		int sign = 1, base = 0, i = 0;
		while (str[i] == ' '){
			++i;
		}
		if (str[i] == '-' || str[i] == '+'){
			sign = 1 - 2 * (str[i++] == '-');
		}
		while (str[i] >= '0' && str[i] <= '9'){
			if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)){
				if (sign == 1){
					return INT_MAX;
				} else{
					return INT_MIN;
				}
			}
			base = 10 * base + (str[i++] - '0');
		}
		return base * sign;
	}

	int myAtoiSS(string str) {
		stringstream ss;
		int res = 0;
		ss << str;
		ss >> res;
		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.myAtoi("1") << endl;
	system("pause");
	return 0;
}