#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size() < 2){
			return 0;
		}
		int vol = 0;
		int i = 0, j = height.size() - 1;
		int mh = min(height[i], height[j]);
		while (i < j){
			if (height[i] < height[j]){
				i++;
				if (height[i] > mh){
					mh = min(height[i], height[j]);
				} else{
					vol += (mh - height[i]);
				}
			} else{
				j--;
				if (height[j] > mh){
					mh = min(height[i], height[j]);
				} else{
					vol += (mh - height[j]);
				}
			}
		}
		return vol;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.trap(vector<int>{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}) << endl;
	system("pause");
	return 0;
}