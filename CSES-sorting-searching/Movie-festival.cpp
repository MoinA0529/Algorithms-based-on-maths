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
    vector<pair<int, int>> a;
    pair<int, int> temp;
    rep(i, 0, n) {
        cin >> temp.first >> temp.second;
        a.push_back(temp);
    }
    sort(a.begin(), a.end(), sortbysec);
    int tmp = 0;
    int res = 0;
    for (auto it : a) {
        if (it.first >= tmp) {
            tmp = it.second;
            res++;
        }
    }
    cout << res << endl;
    return 0;
}