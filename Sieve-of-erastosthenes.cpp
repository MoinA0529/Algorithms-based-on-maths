#include<bits/stdc++.h>
using namespace std;

#define mxN 100007

int spf[mxN];
void sieve() {
	spf[1] = 1;
	for(int i=2;i<mxN;i++) {
		spf[i] = i;
	}
	for(int i=4;i<mxN;i+=2) {
		spf[i] = 2;
	}
	for(int i=3;i*i<mxN;i++) {
		if(spf[i] == i) {
			for(int j=i*i;j<mxN;j+=i) {
				if(spf[j] == j) {
					spf[j] = i;
				}
			}
		}
	}
}

vector<int> getFactorization(int x) {
	vector<int> res;
	while(x!=1) {
		res.push_back(spf[x]);
		x = x/spf[x];
	}
	return res;
}

int main() {
	sieve();
	int x;
	cin>>x;
	vector<int> f = getFactorization(x);
	for(auto it : f) {
		cout<<it<<" ";
	}
	cout<<endl;
	return 0;
}
