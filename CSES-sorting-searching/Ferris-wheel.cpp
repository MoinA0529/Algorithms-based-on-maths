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
	int n, x;
	cin >> n >> x;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	sort(a.begin(), a.end());
	int sub = 0;
	for (int i = 0, j = n - 1; i < j;) {
		while (i < j && a[i] + a[j] > x) {
			j--;
		}
		if (i >= j) break;
		sub++;
		i++;
		j--;
	}
	cout << n - sub << endl;
	return 0;
}