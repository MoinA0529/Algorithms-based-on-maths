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
	int n;
	cin >> n;
	int mod = 7 + pow(10, 9);
	int tmp = 1;
	rep(i, 0, n) {
		tmp = tmp * 2 % mod;
	}
	cout << tmp;
	return 0;
}