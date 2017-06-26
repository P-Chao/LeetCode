#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>

using namespace std;

class Tran{
public:
	string tran(int ibit, int obit, string istr){
		unordered_map<char, int> tabel;
		for (int i = 0; i < 10; ++i){
			tabel.insert({'0'+i, i});
		}
		for (int i = 0; i < 26; ++i){
			tabel.insert({'a'+i, i + 10});
			tabel.insert({'A'+i, i + 36});
		}

		unordered_map<int, char> itable;
		for (int i = 0; i < 10; ++i){
			itable.insert({i, '0' + i});
		}
		for (int i = 0; i < 26; ++i){
			itable.insert({i+10, 'a' + i});
			itable.insert({i+36, 'A' + i});
		}

		long long num = 0, bs = 1;
		const int n = istr.size();
		for (int i = n-1; i >= 0; --i){
			num += (tabel[istr[i]] * bs);
			bs *= ibit;
		}

		char buf[50];
		buf[49] = '\0';
		int i = 49;
		string str;
		while (num > 0){
			int tmp = num % obit;
			num /= obit;
			buf[--i] = itable[tmp];
		}
		return string(buf+i);
	}
};

class Cmp{
public:
	int cmp(int g1, int g2, vector<vector<int>> records, int n){
		const int sz = records.size();
		unordered_map<int, vector<int>> graph;
		for (int i = 0; i < n; ++i){
			if (records[i][0] == records[i][1]){
				continue;
			}
			graph[records[i][0]].push_back(records[i][1]);
		}

		queue<int> q;
		q.push(g1);
		while (!q.empty()){
			int t = q.front();
			q.pop();
			for (int i = 0; i < graph[t].size(); ++i){
				if (g2 == graph[t][i]){
					return 1;
				}
				q.push(graph[t][i]);
			}
		}

		q.push(g2);
		while (!q.empty()){
			int t = q.front();
			q.pop();
			for (int i = 0; i < graph[t].size(); ++i){
				if (g1 == graph[t][i]){
					return -1;
				}
				q.push(graph[t][i]);
			}
		}

		return 0;
	}
};

int main(int argc, char *argv[]){
	Tran tr;
	Cmp c;
	// cout << tr.tran(8, 16, string("12345670")) << endl;
	cout << c.cmp(1, 4, vector<vector<int>>{ {3, 1}, { 3, 4 }, { 1, 1 } }, 3) << endl;
	system("pause");
	return 0;
}