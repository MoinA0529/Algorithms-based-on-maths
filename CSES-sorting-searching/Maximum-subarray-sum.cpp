#include<iostream>
#include<unordered_map>
#include<vector>
#include<map>
#include<algorithm>
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
    int a;
    int msf = -1e18;
    int ans = -1e18;
    rep(i, 0, n) {
        cin >> a;
        msf = Mx(a, msf + a);
        ans = Mx(msf, ans);
    }
    cout << ans << endl;
}