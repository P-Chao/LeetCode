#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		const int h = matrix.size();
		if (h == 0){
			return{};
		}
		const int w = matrix[0].size();
		if (w == 0){
			return{};
		}
		const int a = w*h;
		vector<int> res(a, 0);
		int l = 0, r = w - 1;
		int t = 0, b = h - 1;
		pair<int, int> cur{0, 0};
		int dir_index = 0;
		res[0] = matrix[0][0];
		for (int k = 1; k < a; ++k){
			switch (dir_index) {
			case 0: // go right
				if (cur.first == r){
					k--;
					t++;
					dir_index++;
				} else{
					cur.first++;
					res[k] = matrix[cur.second][cur.first];
				}
				break;
			case 1: // go down
				if (cur.second == b){
					k--;
					r--;
					dir_index++;
				} else{
					cur.second++;
					res[k] = matrix[cur.second][cur.first];
				}
				break;
			case 2: // go left
				if (cur.first == l){
					k--;
					b--;
					dir_index++;
				} else{
					cur.first--;
					res[k] = matrix[cur.second][cur.first];
				}
				break;
			case 3: // go up
				if (cur.second == t){
					k--;
					l++;
					dir_index = 0;
				} else{
					cur.second--;
					res[k] = matrix[cur.second][cur.first];
				}
				break;
			default:
				break;
			}
		}
		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	vector<vector<int>> matrix{ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	auto v = s.spiralOrder(matrix);
	for (auto val : v){
		cout << val << ", ";
	}
	system("pause");
	return 0;
}