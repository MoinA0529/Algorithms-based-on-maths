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
const int mxN = 1e6 + 7;

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

/* ###############################################################################*/
void FourtyTwo() {
	int n;
	cin >> n;
	char a[n + 1][n + 1];
	rep(i, 1, n + 1) {
		rep(j, 1, n + 1) {
			cin >> a[i][j];
		}
	}
	int dp[n + 1][n + 1];
	dp[n][n] = 1;
	for (int i = n; i >= 1; i--) {
		for (int j = n; j >= 1; j--) {
			if (i == n && j == n) {
				dp[n][n] = 1;
				continue;
			}
			if (a[i][j] == '*') {
				dp[i][j] = 0;
				continue;
			}
			int op1 = (i == n) ? 0 : dp[i + 1][j];
			int op2 = (j == n) ? 0 : dp[i][j + 1];
			dp[i][j] = (op1 + op2) % mod;
			if (a[i][j] == '*') dp[i][j] = 0;
		}
	}
	if (a[n][n] == '*') cout << 0 << nl;
	else cout << dp[1][1] % mod << nl;
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