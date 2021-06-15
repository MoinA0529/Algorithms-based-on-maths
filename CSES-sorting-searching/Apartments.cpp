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
	int n, m, k;
	cin >> n >> m >> k;
	vi a(n), b(m);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, m) cin >> b[i];
	//greedy
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int i = 0, j = 0;
	int cnt = 0;
	while (i < n && j < m) {
		if (((a[i] - k) <= b[j]) && ((a[i] + k) >= b[j])) {
			i++;
			j++;
			cnt++;
		} else if (a[i] + k < b[j]) {
			i++;
		} else {
			j++;
		}
	}
	cout << cnt << endl;
	return 0;
}