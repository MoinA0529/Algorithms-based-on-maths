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
	vi a(n + 1, 0);
	rep(i, 0, n - 1) {
		int temp;
		cin >> temp;
		a[temp]++;
	}
	rep(i, 1, n + 1) {
		if (a[i] == 0) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}