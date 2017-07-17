#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>
#include<sstream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void ReplaceAll(std::string& strSource, const std::string& strOld, const std::string& strNew)
{
	int nPos = 0;
	while ((nPos = strSource.find(strOld, nPos)) != strSource.npos)
	{
		strSource.replace(nPos, strOld.length(), strNew);
		nPos += strNew.length();
	}
}

class Solution{
public:
	string reconstructList(string str){
		const int n = 0;
		ReplaceAll(str, string("->"), string(" "));
		ReplaceAll(str, string("NULL"), string(""));
		
		ListNode dummy(0);
		ListNode* node = &dummy;

		stringstream ss;
		ss << str;
		string strtmp;
		while (ss >> strtmp){
			if (ss.fail()){
				break;
			}
			int tmp = atoi(strtmp.c_str());
			node->next = new ListNode(tmp);
			node = node->next;
		}

		ListNode dummy0(0);
		ListNode* node0 = &dummy0;
		while (node->next && node->next->next) {
			auto tmp = node->next->next;
			node0->next = node->next;
			node->next = tmp;
		}
		if (node){
			node->next = dummy0.next;
		}

		char buf[50];
		string res;
		node = &dummy;
		while (node->next) {
			sprintf(buf, "%d", node->next->val);
			res = res + "->" + string(buf);
		}
		res += "->NULL";

		return res.substr(2);
	}

	int longestSubarray(vector<int> nums){
		const int n = nums.size();
		if (n < 2){
			return 0;
		}
		int ans = 0;
		int prev = 0;
		unordered_map<int, int> dp;
		dp.insert({0,-1});
		for (int i = 0; i < n; ++i){
			int tmp = nums[i] ? 1 : -1;
			prev += tmp;
			if (dp.find(prev) != dp.end()){
				ans = max(ans, i-dp[prev]);
			} else{
				dp[prev] = i;
			}
		}
		return ans;
	}
};

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
	Solution s;
	cout << s.reconstructList("1->2->3->4->5->NULL") << endl;
	//cout << s.longestSubarray(vector<int>{0, 0, 0, 1, 0, 1, 1, 1, 1}) << endl;
	system("pause");
	return 0;
}