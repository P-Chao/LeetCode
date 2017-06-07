#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		const int n = citations.size();
		int cnt = 0, i = 0;
		for (i = n - 1; i >= 0; --i){
			if ((n - i) > citations[i]){
				break;
			}
		}
		return (n - i - 1);
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.hIndex(vector<int>{0, 1, 3, 5, 6}) << endl;
	system("pause");
	return 0;
}