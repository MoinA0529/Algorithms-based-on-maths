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
const int mxN = 1e5 + 7;

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
bool isPalindrome(string s) {
	if (s == string(s.rbegin(), s.rend())) return true;
	return false;
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
	//x%=mod;
	while (r > 0 && r <= y) {
		if (r & y) {
			ans *= x;
			//ans%=mod;
		}
		r <<= 1;
		x *= x;
		//x%=mod;
	}
	return ans;
}
string reverse(string s) {
	return string(s.rbegin(), s.rend());
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
int numDig(int n) {
	int cnt = 0;
	for (int num = n; num > 0; num /= 10) cnt++;
	return cnt;
}
int ppow(int a, int n) {
	if (n == 0) return 1;
	else if (n & 1) return a * ppow(a, n - 1);
	else {
		int k = ppow(a, n / 2);
		return k * k;
	}
}

void FourtyTwo() {
	int n;
	cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	set<int> qux;
	qux.insert(0);
	rep(i, 0, n) {
		set<int> tmp;
		for (auto it : qux) {
			tmp.insert(it + a[i]);
		}
		for (auto it : tmp) {
			qux.insert(it);
		}
	}
	qux.erase(0);
	cout << sz(qux) << nl;
	for (auto it : qux) cout << it << " ";
	cout << nl;
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