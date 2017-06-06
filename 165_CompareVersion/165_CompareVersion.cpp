#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {
		const int n1 = version1.size();
		const int n2 = version2.size();
		vector<int> v1, v2;
		int start = 0, i = 0;
		for (i = 0; i < n1; ++i){
			if (version1[i] == '.'){
				v1.push_back(atoi(version1.substr(start, i - start).c_str()));
				start = i + 1;
			}
		}
		if (i != start){
			v1.push_back(atoi(version1.substr(start, i - start).c_str()));
		}

		start = 0;
		for (i = 0; i < n2; ++i){
			if (version2[i] == '.'){
				v2.push_back(atoi(version2.substr(start, i - start).c_str()));
				start = i + 1;
			}
		}
		if (i != start){
			v2.push_back(atoi(version2.substr(start, i - start).c_str()));
		}

		i = -1;
		int n = (v1.size() > v2.size()) ? v1.size() : v2.size();
		while (++i < n){
			int t1 = 0, t2 = 0;
			if (i < v1.size()){
				t1 = v1[i];
			}
			if (i < v2.size()){
				t2 = v2[i];
			}
			if (t1 > t2){
				return 1;
			}
			if (t1 < t2){
				return -1;
			}
		}
		return 0;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.compareVersion("1", "1.1") << endl;
	system("pause");
	return 0;
}