#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	//1. a^b % 1337 = (a % 1337) ^ b % 1337
	//2. xy % 1337 = ((x % 1337) * (y % 1337)) % 1337, 其中xy是一个数字如 : 45, 98等等
	int superPow(int a, vector<int>& b) {
		if (b.empty()){
			return 1;
		}
		a = a % 1337;
		int lastBit = b.back();
		b.pop_back();
		return (superPow(superPow(a, b), 10) * superPow(a, lastBit)) % 1337;
	}
private:
	int superPow(int a, int k){
		if (k == 0){
			return 1;
		}
		int ans = 1;
		for (int i = 1; i <= k; ++i){
			ans = (ans * a) % 1337;
		}
		return ans;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.superPow(2, vector<int>{1, 0}) << endl;
	system("pause");
	return 0;
}
