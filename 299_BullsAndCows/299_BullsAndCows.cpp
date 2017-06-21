#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string getHint(string secret, string guess) {
		const int n = secret.size();
		int bull = 0, cows = 0;
		if (n == 0){
			return string("");
		}

		vector<int> bucket_s(10, 0), bucket_t(10, 0);
		vector<bool> mask(n, false);
		for (int i = 0; i < n; ++i){
			if (secret[i] == guess[i]){
				bull++;
			} else{
				bucket_s[secret[i] - '0']++;
				bucket_t[guess[i] - '0']++;
			}
		}

		for (int i = 0; i < 10; ++i){
			cows += min(bucket_s[i], bucket_t[i]);
		}

		char buf[20];
		sprintf(buf, "%dA%dB", bull, cows);
		return string(buf);
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.getHint("1879", "1890") << endl;
	system("pause");
	return 0;
}