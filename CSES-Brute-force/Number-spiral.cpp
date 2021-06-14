#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define int long long
using namespace std;
int compute(int m) {
    return m * m - m + 1;
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        int temp;
        if (x == y) {
            cout << compute(x) << endl;
        }
        else if (x > y) {
            temp = compute(x);
            if (x % 2 != 0) {
                cout << temp - (x - y) << endl;
            }
            else {
                cout << temp + (x - y) << endl;
            }
        }
        else {
            temp = compute(y);
            if (y % 2 != 0) {
                cout << temp + (y - x) << endl;
            }
            else {
                cout << temp - (y - x) << endl;
            }
        }
    }
    return 0;
}