include <bits/stdc++.h>
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

// A handy function for using  sortbysec argument for sorting an array in increasing/decreasing order
bool myCompare(const pair<int, int> &a, const pair<int, int> &b) {
	return (a.second < b.second);
}

// EUCLIDEAN ALGORITHM for GCD
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
// Input : a, b; where a>b
// This is an implementation of Euclidean algorithm for computing O(N) time complexity
// Make sure that the input are in order


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
// maximum, minimum function in C++ library does not allow direct operations on the result
// Using Conditional operators to implement the same.

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


int spf[mxN];
void sieve() {
	spf[1] = 1;
	for (int i = 2; i < mxN; i++) {
		spf[i] = i;
	}
	for (int i = 4; i < mxN; i += 2) {
		spf[i] = 2;
	}
	for (int i = 3; i * i < mxN; i++) {
		if (spf[i] == i) {
			for (int j = i * i; j < mxN; j += i) {
				if (spf[j] == j) {
					spf[j] = i;
				}
			}
		}
	}
}

vector<int> getFactorization(int x) {
	vector<int> res;
	while (x != 1) {
		res.push_back(spf[x]);
		x = x / spf[x];
	}
	return res;
}

/* ###############################.. Actual Coding starts ..###################################*/

void FourtyTwo() {
	
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
