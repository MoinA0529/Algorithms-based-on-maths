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
const int mxN = 5;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
	x %= mod;
	while (r > 0 && r <= y) {
		if (r & y) {
			ans *= x;
			ans %= mod;
		}
		r <<= 1;
		x *= x;
		x %= mod;
	}
	return ans;
}
void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}
int max3(int a, int b, int c) {
	return max(a, max(b, c));
}
int min3(int a, int b, int c) {
	return min(a, min(b, c));
}
/* ###############################################################################*/

vector<string> a;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


bool isValid(int i, int j, int n, int m) {
	return i >= 0 && j >= 0 && i < n && j < m && a[i][j] != '#';
}

char what(int drx, int dry) {
	if (drx == 1 && dry == 0) {
		return 'D';
	} else if (drx == -1 && dry == 0) {
		return 'U';
	} else if (drx == 0 && dry == 1) {
		return 'R';
	}
	return 'L';
}

string res;

bool bfs(pii A, pii B, int n, int m) {
	vector<vector<bool>> vis(n, vector<bool> (m, false));
	queue<pii> q;
	q.push(mp(A.F, A.S));
	vector<vector<array<int, 2>>> par(n + 1, vector<array<int, 2>> (m + 1, { -1, -1}));
	while (!q.empty()) {
		pii e = q.front();
		q.pop();
		int x = e.F;
		int y = e.S;
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (isValid(tx, ty, n, m) && !vis[tx][ty]) {
				vis[tx][ty] = true;
				q.push(mp(tx, ty));
				par[tx][ty][0] = x;
				par[tx][ty][1] = y;
			}
		}
	}
	int x = B.F;
	int y = B.S;
	if (par[x][y][0] == -1) {
		return false;
	}
	while (a[x][y] != 'A') {
		array<int, 2> e = par[x][y];
		char tmp = what(x - e[0], y - e[1]);
		res.pb(tmp);
		x = e[0];
		y = e[1];
	}
	reverse(all(res));
	return true;
}

void FourtyTwo() {
	int n, m;
	cin >> n >> m;
	a.resize(n);
	rep(i, 0, n) cin >> a[i];
	pii A, B;
	rep(i, 0, n) {
		rep(j, 0, m) {
			if (a[i][j] == 'A') {
				A = {i, j};
			} else if (a[i][j] == 'B') {
				B = {i, j};
			}
		}
	}
	if (!bfs(A, B, n, m)) {
		cout << "NO" << nl;
		return;
	}
	cout << "YES" << nl;
	cout << sz(res) << nl;
	cout << res << nl;
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
