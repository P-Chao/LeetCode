#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
	NumArray(vector<int> nums) {
		const int n = nums.size();
		intel.resize(n);
		if (n == 0){
			return;
		}
		intel[0] = nums[0];
		for (int i = 1; i < n; ++i){
			intel[i] = intel[i - 1] + nums[i];
		}
		return;
	}

	int sumRange(int i, int j) {
		if (i == 0){
			return intel[j];
		}
		if (j == 0){
			return 0;
		}
		return intel[j] - intel[i - 1];
	}
private:
	vector<int> intel;
};

int main(int argc, char *argv[]){
	NumArray obj(vector<int>{1, 2, 3});
	cout << obj.sumRange(1, 2) << endl;
	system("pause");
	return 0;
}