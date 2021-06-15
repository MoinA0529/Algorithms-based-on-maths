#include<iostream>
#include<unordered_map>
#include<vector>
#include<map>
#include<algorithm>
#include<cstdlib>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define rep(i,a,b)    for(int i=a;i<b;i++)
#define vi vector<int>
#define vii vector<int,int>
#define F first
#define S second
#define pb push_back
using std::sort;
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
    IOS;
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    if (n % 2 != 0) {
        int id = (1 + n) / 2;
        id--;
        int median = a[id];
        int res = 0;
        rep(i, 0, n) {
            res += abs(median - a[i]);
        }
        cout << res << endl;
    } else {
        int id = (1 + n) / 2;
        int median = (a[id] + a[id - 1]) / 2;
        int res = 0;
        rep(i, 0, n) {
            res += abs(median - a[i]);
        }
        cout << res << endl;
    }
    return 0;
}