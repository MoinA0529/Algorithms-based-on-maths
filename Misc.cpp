#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e5+7;
const int mod = 1e9+7;

int gcd(int a, int b) {
	if(a<b) swap(a, b);
	if(b == 0) return a;
	return gcd(b, a%b);
}

int binpow(int a, int b) {
	if (b == 0) return 1;
	int res = pow(a, b / 2);
	if (b % 2) return res * res * a;
	else return res * res;
}

int powM(int b, int p, int m) {
	int res = 1;
	while (p) {
		if (p & 1) {
			res = res * b ;
			res = res % m;
		}
		b = b * b;
		b = b % m;
		p /= 2;
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	return 0;
}
