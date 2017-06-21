#include <iostream>
#include <vector>

using namespace std;

class NumArray {
	vector<int> num;
	vector<int> bit;
public:
	NumArray(vector<int> nums) {
		num.resize(nums.size() + 1);
		bit.resize(nums.size() + 1);
		for (int i = 0; i < nums.size(); ++i) {
			update(i, nums[i]);
		}
	}

	void update(int i, int val) {
		int diff = val - num[i + 1];
		for (int j = i + 1; j < num.size(); j += j & (-j)) {
			bit[j] += diff;
		}
		num[i + 1] = val;
	}

	int sumRange(int i, int j) {
		return getSum(j + 1) - getSum(i);
	}

	int getSum(int i) {
		int res = 0;
		for (int j = i; j > 0; j -= j & (-j)) {
			res += bit[j];
		}
		return res;
	}
};

class NumArrayMy {
public:
	NumArrayMy(vector<int> nums) {
		vec = nums;
	}

	void update(int i, int val) {
		if (i < vec.size()){
			vec[i] = val;
		}
		else{
			vec.resize(i + 1);
			vec[i] = val;
		}
	}

	int sumRange(int i, int j) {
		int sum = 0;
		for (int k = i; k <= j; ++k){
			sum += vec[k];
		}
		return sum;
	}

private:
	vector<int> vec;
};

int main(int argc, char *argv[]){
	NumArray obj(vector<int>{1, 3, 5});
	obj.update(1, 2);
	cout << obj.sumRange(0, 2) << endl;
	system("pause");
	return 0;
}