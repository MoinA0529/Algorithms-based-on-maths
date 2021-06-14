#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define rep(i,a,b)    for(int i=a;i<b;i++)
#define vi vector<int>
#define vii vector<int,int>

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
signed main() {
	input_output();
	IOS;
	int n;
	cin >> n;
	int a5 = 0, a2 = 0;
	int tmp = n;
	int i = 1;
	while (tmp > 1) {
		a5 += n / pow(5, i);
		tmp /= 5;
		i++;
	}
	//cout << a5 << " ";
	i = 1;
	tmp = n;
	while (tmp > 1) {
		a2 += n / pow(2, i);
		tmp /= 2;
		i++;
	}
	//cout << a2 << endl;
	cout << Mn(a2, a5) << endl;
	return 0;
}