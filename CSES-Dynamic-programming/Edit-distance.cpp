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
const int mxN = 2e5 + 7;

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
// void swap(int &a, int &b) {
// 	int t = a;
// 	a = b;
// 	b = t;
// }
int max3(int a, int b, int c) {
	return max(a, max(b, c));
}
int min3(int a, int b, int c) {
	return min(a, min(b, c));
}
/* ###############################################################################*/

void FourtyTwo() {
	string word1, word2;
	cin >> word1 >> word2;
	int m = word1.size(), n = word2.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= m; i++) {
		dp[i][0] = i;
	}
	for (int j = 1; j <= n; j++) {
		dp[0][j] = j;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (word1[i - 1] == word2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			} else {
				dp[i][j] = min3(dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]) + 1;
			}
		}
	}
	cout << dp[m][n] << nl;
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