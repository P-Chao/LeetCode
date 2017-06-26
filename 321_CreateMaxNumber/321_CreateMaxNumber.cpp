#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<int> result;
		const int n1 = nums1.size();
		const int n2 = nums2.size();
		for (int i = max(k - n2, 0); i <= min(k, n1); ++i){
			result = max(result, merge(getMax(nums1, i), getMax(nums2, k-i)));
		}
		return result;
	}
private:
	vector<int> merge(vector<int> nums1, vector<int> nums2){
		vector<int> vec;
		while (nums1.size() + nums2.size() > 0){
			vector<int>& tem = nums1 > nums2 ? nums1 : nums2;
			vec.push_back(tem[0]);
			tem.erase(tem.begin());
		}
		return vec;
	}

	vector<int> getMax(vector<int>& nums, int k){
		vector<int> vec;
		int drop = nums.size() - k;
		for (int i = 0; i < nums.size(); ++i){
			while (drop > 0 && vec.size() && nums[i] > vec.back()){ // drop == 0 则只入不出，保证最后总元素数量大于k
				drop--;
				vec.pop_back();
			}
			vec.push_back(nums[i]);
		}
		vec.resize(k);
		return vec;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto vi = s.maxNumber(vector<int>{3, 9}, vector<int>{8, 9}, 3);
	for (auto v : vi){
		cout << v << ", ";
	}
	system("pause");
	return 0;
}
