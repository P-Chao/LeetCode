#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		if (n <= 0){
			return false;
		}
		unordered_set<int> hash;

		while (n != 1){
			hash.insert(n);
			int sum = 0;
			while (n > 0) {
				int tmp = n / 10;
				int t = n - 10 * tmp;
				sum += t*t;
				n = tmp;
			}
			n = sum;
			if (hash.find(n) != hash.end()){
				return false;
			}
		}
		return true;
	}
};

int main(int argc, char *argv[]){
	Solution s; 
	cout << s.isHappy(19) << endl;
	system("pause");
	return 0;
}
