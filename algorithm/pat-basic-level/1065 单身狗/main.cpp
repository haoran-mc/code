// 260303 09:03 Tue
#include <iostream>
#include <map>
#include <set>
using namespace std;
map<int, int> mp;
set<int> st, resst;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        mp[a] = b;
        mp[b] = a;
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        st.insert(a);
    }
    for (auto it = st.begin(); it != st.end(); it++) {
        if (mp.find(*it) == mp.end() || st.count(mp[*it]) == 0) {
            resst.insert(*it);
        }
    }
    cout << resst.size() << endl;
    bool isFirst = true;
    for (auto it = resst.begin(); it != resst.end(); it++) {
        if (it != resst.begin())
            printf(" ");
        printf("%05d", *it);
    }
    return 0;
}
