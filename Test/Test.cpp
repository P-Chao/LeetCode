#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char *argv[]){
	vector<string> s;
	s.resize(3);
	s[0] = string("alice");
	s[1] = string("alicia");
	s[2] = string("bel");
	sort(s.begin(),s.end());
	for (auto ss : s){
		cout << ss << endl;
	}
	system("pause");
	return 0;
}