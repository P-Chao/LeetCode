#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int length = m + n;
		if (length % 2)return findkth(A, m, B, n, length / 2 + 1);
		else return (double(findkth(A, m, B, n, length / 2)) + findkth(A, m, B, n, length / 2 + 1)) / 2;
	}

	int findkth(int A[], int m, int B[], int n, int k){
		if (m>n)
			return findkth(B, n, A, m, k);
		if (m == 0)return B[k - 1];
		if (k == 1)return A[0]<B[0] ? A[0] : B[0];
		int pa = k / 2<m ? k / 2 : m;
		int pb = k - pa;
		if (A[pa - 1] == B[pb - 1]){ return A[pa - 1]; }
		if (A[pa - 1]<B[pb - 1])
			return findkth(A + pa, m - pa, B, pb, k - pa);
		else
			return findkth(A, pa, B + pb, n - pb, k - pb);
	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int i = 0, j = 0, k = 0;
		const int total_size = nums1.size() + nums2.size();
		const int p = total_size / 2;

		nums1.push_back(INT_MAX);
		nums2.push_back(INT_MAX);

		int m1 = 0, m2 = 0;
		while (k != p){
			if (nums1[i] < nums2[j]){
				m1 = nums1[i++];
			} else{
				m1 = nums2[j++];
			}
			k++;
		}

		if (total_size % 2){
			if (nums1[i] < nums2[j]){
				m1 = nums1[i];
			} else{
				m1 = nums2[j];
			}
			return m1;
		} else{
			if (nums1[i] < nums2[j]){
				m2 = nums1[i];
			} else{
				m2 = nums2[j];
			}
			return (m1 + m2) / 2.0f;
		}
		return m1;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.findMedianSortedArrays(vector<int>{1, 3}, vector<int>{2}) << endl;
	system("pause");
	return 0;
}