#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int i = 0, j = height.size() - 1;
		int area = min(height[i], height[j]) * (j - i);
		int len = j;
		while (i != j){
			len--;
			if (height[i] < height[j]){
				i++;
				if (height[i] <= height[i - 1]){
					continue;
				} else{
					area = max(area, min(height[i], height[j]) * len);
				}
			} else{
				j--;
				if (height[j] <= height[j + 1]){
					continue;
				} else{
					area = max(area, min(height[i], height[j]) * len);
				}
			}
		}

		return area;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.maxArea(vector<int>{2,3,10,5,7,8,9}) << endl;
	system("pause");
	return 0;
}
