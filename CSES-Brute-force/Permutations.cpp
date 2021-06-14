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
	if (n <= 3) {
		if (n == 1) cout << "1" << endl;
		else cout << "NO SOLUTION" << endl;
	} else {
		for (int i = 2; i <= n; i += 2) {
			cout << i << " ";
		}
		for (int i = 1; i <= n; i += 2) {
			cout << i << " ";
		}
	}
	cout << endl;
	return 0;
}