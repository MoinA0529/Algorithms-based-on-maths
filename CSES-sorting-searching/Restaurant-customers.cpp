#include<iostream>
#include<unordered_map>
#include<vector>
#include<map>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define rep(i,a,b)    for(int i=a;i<b;i++)
#define vi vector<int>
#define vii vector<int,int>
#define F first
#define S second

using namespace std;
int Mx(int a, int b) {
    if (a < b) return b;
    return a;
}
int Mn(int a, int b) {
    if (a < b) return a;
    return b;
}
signed main() {
    IOS;
    int n;
    cin >> n;
    pair<int, int> tmp;
    map<int, int> a;
    rep(i, 0, n) {
        cin >> tmp.first >> tmp.second;
        a[tmp.first]++;
        a[tmp.second]--;
    }
    int temp = 0, res = -1;
    for (auto it : a) {
        temp += it.second;
        res = Mx(res, temp);
    }
    cout << res << endl;
    return 0;
}