#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define rep(i,a,b)    for(int i=a;i<b;i++)
#define vi vector<int>
#define vii vector<int,int>
#define F first
#define S second
#define pb push_back
void input_output() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
using namespace std;
int Mx(int a, int b) {
	if (a < b) return b;
	return a;
}
int Mn(int a, int b) {
	if (a < b) return a;
	return b;
}
bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
	return (a.second < b.second);
}
signed main() {
	input_output();
	IOS;
	int n;
	cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	multiset<int> aa;
	int cnt = 0;
	rep(i, 0, n) {
		auto it = aa.upper_bound(a[i]);
		if (it == aa.end()) {
			cnt++;
			aa.insert(a[i]);
		} else {
			aa.erase(it);
			aa.insert(a[i]);
		}
	}
	cout << cnt << endl;
	return 0;
}