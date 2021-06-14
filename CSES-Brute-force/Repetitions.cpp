#include<bits/stdc++.h>
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

signed main() {
	input_output();
	IOS;
	string s;
	cin >> s;
	int n = s.size();
	int m = 1;
	int cnt = 1;
	rep(i, 0, n - 1) {
		if (s[i] == s[i + 1]) {
			cnt++;
			if (cnt > m) m = cnt;
		} else {
			cnt = 1;
		}
	}
	cout << m << endl;
	return 0;
}