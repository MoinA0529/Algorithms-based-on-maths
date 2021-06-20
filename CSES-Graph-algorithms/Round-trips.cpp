#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
//using namespace __gnu_pbds;
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
 
//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
int powM(int b, int p, int m) {
	int res = 1;
	while (p) {
		if (p & 1) {
			res = res * b ;
			res = res % m;
		}
		b = b * b;
		b = b % m;
		p /= 2;
	}
	return res;
}
int max3(int a, int b, int c) {
	return max(a, max(b, c));
}
int min3(int a, int b, int c) {
	return min(a, min(b, c));
}
/* ###############################################################################*/
 
vector<int> adj[mxN];
vector<int> parent(mxN, -1);
vector<bool> vis(mxN, false);
int cycle_start, cycle_end;
 
bool dfs(int v, int par) { // passing vertex and its parent vertex
	vis[v] = true;
	for (int u : adj[v]) {
		if (u == par) continue; // skipping edge to parent vertex
		if (vis[u]) {
			cycle_end = v;
			cycle_start = u;
			return true;
		}
		parent[u] = v;
		if (dfs(u, parent[u]))
			return true;
	}
	return false;
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
	bool flg = false;
	cycle_start = -1;
	for (int i = 0; i < n; i++) {
		if (!vis[i] && dfs(i, parent[i])) {
			flg = true;
			break;
		}
	}
	if (cycle_start == -1) {
		cout << "IMPOSSIBLE" << nl;
		return;
	}
	vector<int> res;
	res.pb(cycle_start + 1);
	v = cycle_end;
	while (v != cycle_start) {
		res.pb(v + 1);
		v = parent[v];
	}
	res.pb(cycle_start + 1);
	cout << sz(res) << nl;
	vout(res);
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
