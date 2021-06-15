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


void solve() {
	int n, t;
	cin >> n >> t;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	sort(all(a));
	int l = 0;
	int r = inf;
	while (l < r) {
		int m = (l + r) / 2;
		int p = 0;
		rep(i, 0, n) p += min(m / a[i], (int)1e9);
		//cout<<p<<" ";
		if (p < t) {
			l = m + 1;
		} else {
			r = m;
		}
	}
	cout << l << nl;
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
}