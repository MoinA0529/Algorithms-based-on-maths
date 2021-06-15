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

/* ############################################################### */


signed main() {
	fast_io;
	IOS();
	int n;
	cin >> n;
	map<int, int> a;
	rep(i, 0, n) {
		int tmp;
		cin >> tmp;
		a[tmp]++;
	}
	int res = 0;
	for (auto it : a) {
		res++;
	}
	cout << res << endl;
	return 0;
}