#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define repn(i,a,b) for(int i=a;i>b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define mod 1000000007
#define all(x) x.begin(),x.end()
#define sz(c) (int)c.size()
#define here cout<<"here"<<nl;
#define here1 cout<<"here1"<<nl;
#define vout(a) for(auto iterator:a) {cout<<iterator<<" ";} cout<<nl;
#define inf 1e18
#define nl "\n"
const int mxN = 1e3;
using namespace std;

void IOS() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
	return (a.second < b.second);
}
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
bool isPalindrome(string s) {
	if (s == string(s.rbegin(), s.rend())) return true;
	return false;
}
/* ############################################################### */

string a[mxN];
//bool vis[mxN][mxN];
int n, m;
bool valid(int i, int j) {
	if (i >= 0 && i < n && j >= 0 && j < m && a[i][j] == '.') return true;
	return false;
}
void dfs(int i, int j) {
	//vis[i][j] = true;
	a[i][j] = '#';
	if (valid(i - 1, j)) dfs(i - 1, j);
	if (valid(i + 1, j)) dfs(i + 1, j);
	if (valid(i, j - 1)) dfs(i, j - 1);
	if (valid(i, j + 1)) dfs(i, j + 1);
	return;
}
void solve() {
	cin >> n >> m;
	rep(i, 0, n) cin >> a[i];
	int res = 0;
	rep(i, 0, n) {
		rep(j, 0, m) {
			if (valid(i, j)) {
				dfs(i, j);
				res++;
			}
		}
	}
	cout << res << nl;
	return;
}

signed main() {
	fast_io;
	IOS();
	int t = 1; //cin >> t;
	rep(tc, 0, t) {
		//cout << "CASE[" << tc + 1 << "] : " << nl;
		solve();
	}
	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	return 0;