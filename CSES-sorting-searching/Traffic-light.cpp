#include<iostream>
#include<unordered_map>
#include<vector>
#include<map>
#include<algorithm>
#include<cstdlib>
#include<set>
#include<iterator>
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
    int x, n;
    cin >> x >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    set<int> aa;
    aa.insert(0);
    aa.insert(x);
    map<int, int> mp;
    mp[x] = 1;
    rep(i, 0, n) {
        auto it = aa.lower_bound(a[i]);
        int r = *it;
        --it;
        int l = *it;
        int tmp = r - l;
        --mp[tmp];
        if (mp[r - l] == 0) mp.erase(r - l);
        aa.insert(a[i]);
        ++mp[r - a[i]];
        ++mp[a[i] - l];
        cout << (--mp.end())->first << " ";
    }
    cout << endl;
    return 0;
}
