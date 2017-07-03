#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int shortestDistance(vector<string>& words, string word1, string word2) {
		const int n = words.size();
		int prev1 = -n, prev2 = -n, distance = n;
		for (int i = 0; i < n; ++i){
			if (words[i] == word1){
				distance = min(distance, i - prev2);
				prev1 = i;
			} else if (words[i] == word2){
				distance = min(distance, i - prev1);
				prev2 = i;
			}
		}
		return distance;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.shortestDistance(vector<string>{"practice", "makes", "perfect", "coding", "makes"}, "coding", "practice") << endl;
	system("pause");
	return 0;
}
