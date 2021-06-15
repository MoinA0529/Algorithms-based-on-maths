#include <bits/stdc++.h>
using namespace std;
/*
Mathematical Fact:
(n/1)+(n/2)+(n/3)+....(n/n) = O(nlogn)

*/
/*
This code deals with prime factorisation of any number in O(logn)
*/
const int N = 100023;
int main() {
    int primefactor[N];
    // primefactor[i] stores the largest prime number which divides i
    // For eg primefactor[3]=3, primefactor[15]=5
    for (int i = 1; i < N; i++)
    {
        primefactor[i] = i;
    }
    for (int i = 2; i < N; i++)
    {
        if (primefactor[i] != i) // i.e. i is not prime
            continue;
        for (int j = i; j < N; j += i)
            primefactor[j] = i; // Since i is prime and divides j
    }
    /*
        This is the precomputation part
        Complexity of above part is:
        (N/2)+(N/3)+(N/5)+(N/7)+.... which is less than (N/1)+(N/2)+...(N/N)=O(NlogN)
    */
    // Now for any number x<N we can prime factorise it in O(logn) time
    int x = 100;
    // Lets count no. of factors of x
    int factors = 1;
    while (x != 1)
    {
        int p = primefactor[x]; // p is prime and divides x
        int cnt = 0; // It will store the maximum power of p dividing x
        while ((x % p) == 0)
        {
            x /= p;
            cnt++;
        }
        factors *= (cnt + 1);
    }
    cout << factors << '\n';
    return 0;
}