#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		const int n = numbers.size();
		auto i = 0, j = (n - 1);
		while (i != j){
			int t = numbers[i] + numbers[j];
			if (t > target){
				j--;
			} else if (t < target){
				i++;
			} else{
				return{i+1,j+1};
			}
		}
		return{ 0, 0 };
	}
};

int main(int argc, char *argv[]){
	Solution s;
	s.twoSum(vector<int>{2, 7, 11, 15}, 9);
	system("pause");
	return 0;
}