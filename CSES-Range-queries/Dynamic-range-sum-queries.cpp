#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define nl "\n"
#define vout(a) for(auto iterator:a) {cout<<iterator<<" ";} cout<<'\n';
#define vout2d(a) for(auto iterator:a) {for(auto it:iterator) {cout<<it<<" ";} cout<<"\n";}

const int mxN = 2e5 + 7;
const int mod = 1e9 + 7;
const int inf = 1e15;

vector<int> tree;
int n;
void build(vector<int> &a, int v, int tl, int tr) {
	if (tl == tr) {
		tree[v] = a[tl];
	} else {
		int tm = (tl + tr) / 2;
		build(a, v * 2, tl, tm);
		build(a, v * 2 + 1, tm + 1, tr);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
}
int sum(int a, int b) {
	a += n; b += n;
	int s = 0;
	while (a <= b) {
		if (a % 2 == 1) s += tree[a++];
		if (b % 2 == 0) s += tree[b--];
		a /= 2; b /= 2;
	}
	return s;
}
int sum(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr) {
		return tree[v];
	}
	int tm = (tl + tr) / 2;
	return sum(v * 2, tl, tm, l, min(r, tm))
	       + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
void update(int k, int x) {
	k += n;
	tree[k] += x;
	for (k /= 2; k >= 1; k /= 2) {
		tree[k] = tree[2 * k] + tree[2 * k + 1];
	}
}
void update(int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr) {
		tree[v] = new_val;
	} else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update(v * 2, tl, tm, pos, new_val);
		else
			update(v * 2 + 1, tm + 1, tr, pos, new_val);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
}
void solve() {
	int q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	tree.resize(4 * n, 0);
	build(a, 1, 0, n - 1);
	while (q--) {
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 2) {
			cout << sum(1, 0, n - 1, --l , --r) << nl;
		} else {
			update(1, 0, n - 1, --l, r);
		}
	}
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
		solve();
	}
	return 0;
}
