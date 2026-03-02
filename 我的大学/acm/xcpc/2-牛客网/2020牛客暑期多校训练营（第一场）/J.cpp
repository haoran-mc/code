#include<iostream>
using namespace std;

int main()
{
    long long n;
    long long p = 1;
    long long q = 1;
    long long num = 9982244353;
    cin >> n;
    for(long long i = 0; i <= n; i++) {
        p *= i;
    }
    for(long long i = n+1; i <= n-1; i++) {
        q *= i;
    }
    for(long long k = 0; ; k++) {
        if(num * k + p / q);
    }
}