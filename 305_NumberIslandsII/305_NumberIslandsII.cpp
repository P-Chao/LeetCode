#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
		vector<vector<int>> mp(m, vector<int>(n, 0));
		vector<int> result;
		int num = 0;
		vector<int> par(m*n);
		for (int i = 0; i < m*n; i++) par[i] = i;
		for (auto val : positions)
		{
			vector<pair<int, int>> dir{ { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
			for (auto val2 : dir)
			{
				int x = val.first, y = val.second, px = x + val2.first, py = y + val2.second;
				if (px<0 || px >= m || py<0 || py >= n || !mp[px][py]) continue;
				int par1 = x*n + y, par2 = px*n + py;
				while (par[par1] != par1) par[par1] = par[par[par1]], par1 = par[par1];
				while (par[par2] != par2) par[par2] = par[par[par2]], par2 = par[par2];
				if (par1 != par2) par[par2] = par1, num--;
			}
			mp[val.first][val.second] = 1;
			result.push_back(++num);
		}
		return result;
	}

	vector<int> numIslands2My(int m, int n, vector<pair<int, int>>& positions) {
		const int sz = positions.size();
		unordered_map<long long, int> hash;
		vector<int> result(sz, 0), par(sz, 0);
		for (int i = 0; i < sz; ++i){
			
		}
		int num = 0;
		int dir[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };
		for (int i = 0; i < sz; ++i){
			par[i] = i;
			num++;
			long long id1 = positions[i].first + ((long long)positions[i].second << 32);
			hash[id1] = i + 1;
			for (int d = 0; d < 4; ++d){
				int x = positions[i].first + dir[d][0];
				int y = positions[i].second + dir[d][1];
				long long id2 = x + ((long long)y << 32);
				if (hash[id2]){
					int p1 = i;
					int p2 = hash[id2] - 1;
					while (par[p1] != p1) {
						par[p1] = par[par[p1]];
						p1 = par[p1];
					}
					while (par[p2] != p2) {
						par[p2] = par[par[p2]];
						p2 = par[p2];
					}
					if (p1 != p2){
						par[p2] = p1;
						num--;
					}
				}
			}
			result[i] = num;
		}
		return result;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	auto rv = s.numIslands2(3, 3, vector<pair<int, int>>{{0, 0}, {0, 1}, {1, 2}, {2, 1}});
	for (auto v : rv){
		cout << v << ", ";
	}
	system("pause");
	return 0;
}