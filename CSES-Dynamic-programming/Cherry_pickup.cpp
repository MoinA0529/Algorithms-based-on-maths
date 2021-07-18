#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define nl "\n"
#define vout(a) for(auto iterator:a) {cout<<iterator<<" ";} cout<<'\n';
#define vout2d(a) for(auto iterator:a) {for(auto it:iterator) {cout<<it<<" ";} cout<<"\n";}

class Solution {
public :
	void Solve();
private :
	int n, m;
	vector<vector<int>> a;
	vector<vector<vector<int>>> dp;
	int helper(int r1, int c1, int c2, int N);
	bool isValid(int x, int y, int n);
	int max4(int a, int b, int c, int d);
	const int mod = 1e9 + 7;
	const int inf = 1e18;
	const int mxN = 1e6 + 7;
};

bool Solution :: isValid(int x, int y, int n) {
	return x >= 0 && y >= 0 && x < n && y < n;
}

int Solution :: max4(int a, int b, int c, int d) {
	return max(max(a, b), max(c, d));
}

int Solution :: helper(int r1, int c1, int c2, int N) {
	int r2 = r1 + c1 - c2;
	if (!isValid(r1, c1, N) || !isValid(r2, c2, N) || a[r1][c1] == -1 || a[r2][c2] == -1) return INT_MIN;
	if (dp[r1][c1][c2] != -1) return dp[r1][c1][c2];
	if (r1 == N - 1 && c1 == N - 1) return a[r1][c1];
	int ans = a[r1][c1];
	if (c1 != c2) ans += a[r2][c2];
	int tmp = max4(helper(r1, c1 + 1, c2, N),
	               helper(r1 + 1, c1, c2, N),
	               helper(r1 + 1, c1, c2 + 1, N),
	               helper(r1, c1 + 1, c2 + 1, N)
	              );
	ans += tmp;
	dp[r1][c1][c2] = ans;
	return ans;
}

void Solution :: Solve() {
	dp.resize(101, vector<vector<int>> (101, vector<int> (101, -1)));
	int n;
	cin >> n;
	a.resize(n, vector<int> (n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	cout << max(0ll, helper(0, 0, 0, n));
	return;
}

signed main() {
	IOS;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		Solution obj;
		obj.Solve();
	}
	return 0;
}
