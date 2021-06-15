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

/* ############################################################### */

int wrap(int n, int i, int add) {
	if (i + add <= n) return i + add;
	else return (i + add) % n;
}

void solve() {
	int n;
	cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	int cnt = 0;
	int curr = 0;
	map<int, int> remd;
	if (n == 1) {
		cout << 1 << nl;
		return;
	}
	while (cnt < n) {
		cnt++;
		int t = 2;
		while (t > 0) {
			curr = wrap(n, curr, 1);
			if (remd[curr] != 1) t--;
		}
		cout << curr << " ";
		remd[curr] = 1;
	}
	cout << nl;
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