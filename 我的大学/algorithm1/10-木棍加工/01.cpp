#include <map>
#include <iostream>
using namespace std;
#define i_ i->first
#define i__ i->second
#define st0_ st0.begin()
map<int, int> st, st0;

int main()
{
    int n, p = 0, q, k;
    cin >> n;
    while (++p < n) {
        cin >> q >> k;
        st[q] = k;
    }
    auto i = st.begin();
    auto j = st0_;
    for (; ++i != st.end();) {
        for (j = st0_; ++j != st0.end();) {
            if (i_ >= j->first && i__ >= j->second) {
                st0[i_] = i__;
                break;
            }
            if (j == st0.end())
                st0[i_] = i__;
        }
    }
    cout << st0.size();
    return 0;
}

