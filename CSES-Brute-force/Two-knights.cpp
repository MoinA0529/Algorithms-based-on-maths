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
	for (int k = 1; k <= n; k++) {
		int tmp = (k * k) * (k * k - 1) * 0.5;
		if (k > 2) {
			tmp -= 4 * (k - 1) * (k - 2);
		}
		cout << tmp << endl;
	}
	return 0;
}