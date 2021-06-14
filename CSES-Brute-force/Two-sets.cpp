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
    int sum = n * (n + 1) / 2;
    if (n <= 2) cout << "NO" << endl;
    else if (sum % 2 != 0) cout << "NO" << endl;
    else {
        if (n % 2 != 0) { //sum%2==0 and n is odd
            int i = n;
            vi frst_hlf;
            vi scd_hlf;
            int hlf_sum = 0;
            while ((hlf_sum < sum / 2) && (hlf_sum + i <= sum / 2)) {
                frst_hlf.push_back(i);
                hlf_sum += i;
                i--;
            }
            int tmp = sum / 2 - hlf_sum;
            if (tmp != 0) {
                frst_hlf.push_back(tmp);
            }
            while (i > 0) {
                if (i != tmp) {
                    scd_hlf.push_back(i);
                }
                i--;
            }
            cout << "YES" << endl;
            cout << frst_hlf.size() << endl;
            for (auto it : frst_hlf) {
                cout << it << " ";
            }
            cout << endl;
            cout << scd_hlf.size() << endl;
            for (auto it : scd_hlf) {
                cout << it << " ";
            }
            cout << endl;
        } else {//sum%4==0 and n is even
            vi f;
            vi s;
            int hlf_sum = 0;
            int i = 1;
            int tmp = n;
            while (hlf_sum < sum / 2) {
                hlf_sum += (i + tmp);
                f.push_back(i);
                f.push_back(tmp);
                i++;
                tmp--;
            }
            while (tmp - i >= 1) {
                s.push_back(i);
                s.push_back(tmp);
                i++;
                tmp--;
            }
            cout << "YES" << endl;
            cout << f.size() << endl;
            for (auto it : f) {
                cout << it << " ";
            }
            cout << endl;
            cout << s.size() << endl;
            for (auto it : s) {
                cout << it << " ";
            }
            cout << endl;
        }
    }
    return 0;
}