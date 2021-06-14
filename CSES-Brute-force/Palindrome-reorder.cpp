#include<bits/stdc++.h>
#include<unordered_map>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define rep(i,a,b)    for(int i=a;i<b;i++)
#define vi vector<int>
#define vii vector<int,int>
void input_output() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
using namespace std;
int Mx(int a, int b) {
	if (a < b) return b;
	return a;
}
int Mn(int a, int b) {
	if (a < b) return a;
	return b;
}
signed main() {
	input_output();
	IOS;
	string s;
	cin >> s;
	std::unordered_map<char, int> freq;
	rep(i, 0, s.size()) freq[s[i]]++;
	int odd_count = 0;
	char odd_char;
	unordered_map<char, int>::iterator it;
	for (auto it : freq) {
		if (it.second % 2 != 0) {
			odd_char = it.first;
			odd_count++;
		}
	}
	if (odd_count > 1 || (odd_count == 1 && s.size() % 2 == 0)) {
		cout << "NO SOLUTION" << endl;
		return 0;
	}
	string Frst_hlf = "";
	string Scd_hlf = "";

	for (auto it : freq) {
		string tmp(it.second / 2, it.first);
		Frst_hlf = Frst_hlf + tmp;
		Scd_hlf = tmp + Scd_hlf;
	}
	string res;
	if (odd_count == 1) {
		res = Frst_hlf + odd_char + Scd_hlf;
	} else {
		res = Frst_hlf + Scd_hlf;
	}
	cout << res << endl;
	return 0;
}