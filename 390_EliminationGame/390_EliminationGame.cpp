#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
	int lastRemaining(int n) {
		return f(n);
	}
private:
	int f(int n){ // left to right
		if (n < 3){
			return n;
		}
		if (n & 1){
			return 2 * g((n-1)/2);
		} else{
			return 2 * g(n/2);
		}
	}
	int g(int n){ // right to left
		if (n < 3){
			return 1;
		}
		if (n & 1){
			return 2 * f((n-1)/2);
		} else{
			return 2 * f(n/2) - 1;
		}
	}
private:
	using PQ = priority_queue<int, vector<int>, function<bool(const int&, const int&)>>;
public:
	int lastRemainingTEL(int n) {
		auto cmp1 = [](const int& lhs, const int& rhs)->bool{ return lhs > rhs; };
		auto cmp2 = [](const int& lhs, const int& rhs)->bool{ return lhs < rhs; };
		PQ p(cmp1), q(cmp2);
		if (n < 3){
			return n;
		}
		for (int i = 1; i <= n; ++i){
			if (!(i & 1)){
				q.push(i);
			}
		}
		int t = 0;
		bool flag = false;
		while (!p.empty() || !q.empty()){
			bool del = true;
			if (flag){
				while (!p.empty()){
					t = p.top();
					p.pop();
					if (!del){
						q.push(t);
					}
					del = !del;
				}
			} else{
				while (!q.empty()) {
					t = q.top();
					q.pop();
					if (!del){
						p.push(t);
					}
					del = !del;
				}
			}
			flag = !flag;
		}
		return t;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.lastRemaining(6690) << endl;
	system("pause");
	return 0;
}