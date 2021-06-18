#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define repn(i,a,b) for(int i=a;i>b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
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
#define ar array<int,2>

const int mod = 1000000007;
const int inf = 1e18;
const int mxN = 2e5 + 5;

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

// const int N = 2e7+10;
// int dp[N];
// void sieve() {
// 	rep(i,2,N) {
// 		if(dp[i]!=0) continue;
// 		else {
// 			for(int j=i;j<N;j+=i) {
// 				dp[j]++;
// 			}
// 		}
// 	}
// 	rep(i,0,N) {
// 		int t = dp[i];
// 		dp[i] = powM(2,t);
// 	}
// }

/* ###############################################################################*/

int a[mxN];
int m[mxN][17];

int query(int l, int r) {
	int length = r - l + 1;
	int k = 0;
	while (1 << (k + 1) <= length) {
		k++;
	}
	return mn(m[l][k], m[r - (1 << k) + 1][k]);
}

void FourtyTwo() {
	int n, q;
	cin >> n >> q;
	vi a(n);
	rep(i, 0, n) {
		cin >> a[i];
		m[i][0] = a[i];
	}
	for (int k = 1; k < 20; k++) {
		for (int i = 0; i + (1 << k) - 1 < n; i++) {
			m[i][k] = mn(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
		}
	}
	int l, r;
	rep(i, 0, q) {
		cin >> l >> r;
		l--;
		r--;
		cout << query(l, r) << nl;
	}
	return;
}

signed main() {
	fast_io;
	IOS();
	//sieve();
	int t = 1; //cin >> t;
	rep(tc, 0, t) {
		//cout << "____CASE[" << tc + 1 << "] : " << nl;
		FourtyTwo();
	}
	return 0;
}
