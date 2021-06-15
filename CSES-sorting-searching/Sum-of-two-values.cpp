#include<iostream>
#include<unordered_map>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define rep(i,a,b)    for(int i=a;i<b;i++)
#define vi vector<int>
#define vii vector<int,int>
#define F first
#define S second
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
    int n, x;
    cin >> n >> x;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    // stl implementation
    map<int, int> aa;
    rep(i, 0, n) aa[a[i]] = i + 1;
    int res1 = -1000000, res2 = -1000000;
    rep(i, 0, n) {
        if (aa[x - a[i]] > 0) {
            res1 = i;
            res2 = aa[x - a[i]];
            //cout<<res1<<", "<<res2<<endl;
            if (res1 + 1 == res2) continue;
            break;
        }
    }
    if (res1 + 1 == res2 || (res1 == -1000000 || res2 == -1000000)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << res1 + 1 << " " << res2 << endl;
    return 0;
}