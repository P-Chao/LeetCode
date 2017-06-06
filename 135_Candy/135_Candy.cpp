#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings){
		// there are two cases: up-ward and down-ward
		// the start-point of up-ward must be 1 candy
		// the down-ward is tricky, say s[i] is the peak value, it can hold s[i] elements afterwards by decreasing by 1 for each element
		// once the s[i+1] exceed the s[i] we need to increase s[i]
		// what about equal? equal can be considered as either upward or down-ward
		// for example [5, 5, 5, 5, 4] get 6 candies in total
		if (ratings.size() == 0){
			return 0;
		}

		int peak = 0, peakCandy = 1, prevCandy = 1, totalCandy = 1;

		for (int k = 1; k < ratings.size(); ++k){
			if (ratings[k] > ratings[k - 1]){
				peak = k;
				peakCandy = (++prevCandy);
				totalCandy += prevCandy;
			} else if (ratings[k] < ratings[k - 1]){
				totalCandy += (k - peak); // 下降时，需要根据峰的位置进行判断
				if (k - peak >= peakCandy){
					totalCandy += 1;
				}
				prevCandy = 1;
			} else{  // == reset
				totalCandy += 1;
				peak = k;
				peakCandy = 1;
				prevCandy = 1;
			}
		}

		return totalCandy;
	}

	int candyMyQ(vector<int>& ratings) {
		const int n = ratings.size();
		if (n < 2){
			return n;
		}
		
		queue<int> q;
		vector<int> candy(n, 0);
		if (ratings[0] <= ratings[1]){
			q.push(0);
			candy[0] = 1;
		}
		if (ratings[n - 2] >= ratings[n - 1]){
			q.push(n-1);
			candy[n-1] = 1;
		}
		for (int i = 1; i < n-1; ++i){
			if (ratings[i] <= ratings[i - 1] && ratings[i] <= ratings[i - 1]){
				q.push(i);
				candy[i] = 1;
			}
		}

		while (!q.empty()){
			auto t = q.front();
			q.pop();
			int cnt = candy[t];
			int id = t + 1;
			int icnt = cnt;
			while (id < n){
				if (ratings[id] > ratings[id - 1]){
					icnt++;
					if (icnt > candy[id]){
						candy[id] = icnt;
					}
				} else{
					break;
				}
				id++;
			}
			id = t - 1;
			icnt = cnt;
			while (id >= 0){
				if (ratings[id] > ratings[id + 1]){
					icnt++;
					if (icnt > candy[id]){
						candy[id] = icnt;
					}
				} else{
					break;
				}
				id--;
			}
		}

		int res = 0;
		for (auto v : candy){
			res += v;
		}
		return res;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.candy(vector<int>{1, 2, 2}) << endl;
	system("pause");
	return 0;
}