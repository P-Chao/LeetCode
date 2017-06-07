#include <iostream>
#include <cstdint>

using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int cnt = 0;
		while (n > 0){
			if (n & 0x01){
				cnt++;
			}
			n = n >> 1;
		} 
		return cnt;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.hammingWeight(1) << endl;
	system("pause");
	return 0;
}