#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define repn(i,a,b) for(int i=a;i>b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define mod 1000000007
#define all(x) x.begin(),x.end()
#define w(t) int t; cin>>t; while(t--)
#define sz(c) (int)c.size()
#define here cout<<"here"<<endl;
#define here1 cout<<"here1"<<endl;
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

/* ############################################################################## */


signed main() {
	fast_io;
	IOS();
	w(t) {
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		int tmp = a - (b - a);
		if (tmp >= 0) {
			if (tmp % 3 == 0) cout << "YES" << endl;
			else cout << "NO" << endl;
		} else cout << "NO" << endl;
	}
	return 0;
}