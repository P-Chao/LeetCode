#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int countPrimes(int n) {
		bool *mask = new bool[n];
		int count = 0;
		for (int i = 2; i < n; ++i){
			if (!mask[i]){
				count++;
				for (int j = 2; j * i < n; ++j){
					mask[j * i] = true;
				}
			}
		}
		delete mask;
		return count;
	}

	int countPrimesTLE(int n){  
		int *mask = new int[n];
		int count = 0;
		for (int i = 2; i <= n; ++i){
			if (isPrime(i)){
				count++;
			}
		}
		delete mask;
		return count;
	}
private:
	bool isPrime(int n){
		if (n == 1){
			return false;
		}
		for (int i = 2; i * i <= n; ++i){
			if (n % i == 0){
				return false;
			}
		}
		return true;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.countPrimes(10) << endl;
	system("pause");
	return 0;
}