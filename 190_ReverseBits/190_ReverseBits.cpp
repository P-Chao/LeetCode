#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t r = 0;
		int i = 32;
		while (i--){
			int t = n & 0x01;
			r = r * 2 + t;
			n = n >> 1;
		}
		return r;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.reverseBits(43261596) << endl;
	system("pause");
	return 0;
}