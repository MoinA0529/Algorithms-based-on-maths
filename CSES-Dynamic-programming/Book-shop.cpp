#include <bits/stdc++.h>
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

/* ###############################################################################*/

void FourtyTwo() {
	int n, W;
	cin >> n >> W;
	vi w(n + 1), v(n + 1);
	rep(i, 1, n + 1) cin >> w[i];
	rep(i, 1, n + 1) cin >> v[i];
	vi dp(W + 1, 0);
	rep(i, 1, n + 1) {
		for (int j = W; j >= w[i]; j--) {
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	int res = 0;
	rep(i, 0, W + 1) {
		res = max(res, dp[i]);
	}
	cout << res << nl;
	return ;
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