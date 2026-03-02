#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
#define _max(a, b) (a > b ? a : b)
#define _min(a, b) (a < b ? a : b)

template <typename T>
T Smax(T x) {return x;}
template<typename T, typename... Args>
T Smax(T a, Args... args) {
    return _max(a, Smax(args...));
}
template <typename T>
T Smin(T x) {return x;}
template<typename T, typename... Args>
T Smin(T a, Args... args) {
    return _min(a, Smin(args...));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout)
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int a, b, c, n;
    // scanf("%d %d %d %d", &a, &b, &c, &n);
    cin >> a >> b >> c >> n;
    int maxi = Smax(a, b, c);
    int mini = Smin(a, b, c);
    int sum  = a + b + c;
    int seco = sum - maxi - mini;
    if (maxi + seco - mini - n > 0) {
        cout << "NO" << "\n";
        return 0;
    }
    string s1, s2, s3;
    for (int i = 0; i < mini; ++i) {
        s1 += "a";
        s2 += "a";
        s3 += "a";
    }
    {
        if (a == seco) {
            int add = seco - mini;
            for (int i = 0; i < add; ++i) {
                s1 += "b";
                s2 += "b";
            }
        } else if (b == seco) {
            int add = seco - mini;
            for (int i = 0; i < add; ++i) {
                s2 += "b";
                s3 += "b";
            }
        } else if (c == seco) {
            int add = seco - mini;
            for (int i = 0; i < add; ++i) {
                s1 += "b";
                s3 += "b";
            }
        }
    }
    {
        if (a == maxi) {
            int add1 = maxi - mini;
            int add2 = maxi - mini;
            for (int i = 0; i < add1; ++i)
                s1 += "c";
            for (int i = 0; i < add2; ++i)
                s2 += "c";
        } else if (b == maxi) {
            int add2 = maxi - mini;
            int add3 = maxi - mini;
            for (int i = 0; i < add2; ++i)
                s2 += "c";
            for (int i = 0; i < add3; ++i)
                s3 += "c";
        } else if (c == maxi) {
            int add1 = maxi - mini;
            int add3 = maxi - mini;
            for (int i = 0; i < add1; ++i)
                s1 += "c";
            for (int i = 0; i < add3; ++i)
                s3 += "c";
        }
    }
    {
        int left1 = n - (int)s1.length();
        for (int i = 0; i < left1; ++i) {
            s1 += "x";
        }
        int left2 = n - (int)s2.length();
        for (int i = 0; i < left2; ++i) {
            s2 += "y";
        }
        int left3 = n - (int)s3.length();
        for (int i = 0; i < left3; ++i) {
            s3 += "z";
        }
    }
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    return 0;
}
