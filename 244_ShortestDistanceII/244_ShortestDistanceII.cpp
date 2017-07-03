#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class WordDistance {
public:
	WordDistance(vector<string> words) {
		for (int i = 0; i < words.size(); ++i){
			hash[words[i]].push_back(i);
		}
	}

	int shortest(string word1, string word2) {
		int i = 0, j = 0, dist = INT_MAX;
		while (i < hash[word1].size() && j < hash[word2].size()) {
			int id1 = hash[word1][i];
			int id2 = hash[word2][j];
			dist = min(dist, abs(id1 - id2));
			(id1 > id2) ? ++j : ++i;
		}
		return dist;
	}
private:
	unordered_map<string, vector<int>> hash;
};

int main(int argc, char *argv[]){
	WordDistance w(vector<string>{"practice", "makes", "perfect", "coding", "makes"});
	cout << w.shortest("coding", "practice") << endl;
	system("pause");
	return 0;
}