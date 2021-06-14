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
int Max(int a, int b) {
	if (a > b) return a;
	return b;
}
signed main() {
	input_output();
	IOS;
	int n;
	cin >> n;
	vi a(n);
	int temp;
	rep(i, 0, n) {
		cin >> a[i];
	}
	int cnt = 0;
	int mx = a[0];
	rep(i, 0, n - 1) {
		if (a[i + 1] < mx) {
			cnt += mx - a[i + 1];
		}
		mx = Max(a[i + 1], mx);
	}
	cout << cnt << endl;
	return 0;
}