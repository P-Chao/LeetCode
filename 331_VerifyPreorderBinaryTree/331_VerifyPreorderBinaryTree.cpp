#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool isValidSerialization(string preorder) {
		const int n = preorder.size();
		int pre = -1, node = 0, leaf = 0;
		bool isend = false;
		for (int i = 0; i < n; ++i){
			string str;
			if (preorder[i] == ','){
				str = preorder.substr(pre + 1, i - pre - 1);
				pre = i;
			} else if (i == n - 1){
				str = preorder.substr(pre + 1);
			} else{
				continue;
			}
			if (str == "#"){
				leaf++;
			} else if (str.empty()){
				return false;
			} else{
				node++;
			}
			if (isend){
				return false;
			}
			if (leaf > node){
				isend = true;
			}
		}
		return leaf == (node+1);
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
	system("pause");
	return 0;
}