#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> grayCode(int n){
		vector<int> res;
		res.push_back(0);
		int inc = 1;
		for (int i = 1; i <= n; ++i){ // 循环式，所有都是镜像复现的
			for (int i = res.size() - 1; i >= 0; --i){
				res.push_back(res[i]+inc);
			}
			inc *= 2;
		}
		return res;
	}

	vector<int> grayCodeFM(int n) { 
		vector<int> v;
		const int l = (1 << n);
		for (int i = 0; i < l; ++i){
			v.push_back(i ^ (i >> 1));
		}
		return v;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto vr = s.grayCode(4);
	for (auto v : vr){
		cout << v << ", ";
	}
	system("pause");
	return 0;
}