#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i,a,b) for(int i=a;i<b;++i)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define sz(c) (int)c.size()
#define clr(a) memset((a),0,sizeof(a))
#define here cout<<"here"<<nl;
#define here1 cout<<"here1"<<nl;
#define vout(a) for(auto iterator:a) {cout<<iterator<<" ";} cout<<'\n';
#define debug(x) cerr<<#x<<" = "<<x<<endl;
#define nl "\n"
 
#define int long long int
#define ld long double
#define vi vector<int>
#define pii pair<int, int>
 
const int mod = 1000000007;
const int inf = 1e18;
const int mxN = 2e5;
 
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*
    find_by_order() - Returns an iterator to the k-th largest element (counting from zero)
    order_of_key()  - The number of items in a set that are strictly smaller than our item
    Rest same as set
*/
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
int binpow(int a, int b) {
	if (b == 0) return 1;
	int res = pow(a, b / 2);
	if (b % 2) return res * res * a;
	else return res * res;
}
int mx(int a, int b) {
	return a > b ? a : b;
}
int mn(int a, int b) {
	return a > b ? b : a;
}
int powM(int x, int y) {
	int ans = 1, r = 1;
	//x %= mod;
	while (r > 0 && r <= y) {
		if (r & y) {
			ans *= x;
			//ans %= mod;
		}
		r <<= 1;
		x *= x;
		//x %= mod;
	}
	return ans;
}
int max3(int a, int b, int c) {
	return max(a, max(b, c));
}
int min3(int a, int b, int c) {
	return min(a, min(b, c));
}
/* ###############################################################################*/
 
vi adj[mxN];
vector<bool> vis(mxN, false);
 
void dfs(int u) {
	if (vis[u]) return;
	vis[u] = true;
	for (auto i : adj[u]) {
		if (!vis[i]) dfs(i);
	}
	return;
}
 
void FourtyTwo() {
	int n, m;
	cin >> n >> m;
	int u, v;
	rep(i, 0, m) {
		cin >> u >> v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	vi ans;
	rep(i, 0, n) {
		if (!vis[i]) {
			ans.pb(i);
			dfs(i);
		}
	}
	cout << sz(ans) - 1 << nl;
	rep(i, 1, sz(ans)) {
		cout << ans[0] + 1 << " " << ans[i] + 1 << nl;
	}
	return;
}
 
signed main() {
	fast_io;
	IOS();
	int t = 1; //cin >> t;
	rep(tc, 0, t) {
		//cout << "____CASE[" << tc + 1 << "] : " << nl;
		FourtyTwo();
	}
	return 0;
}
