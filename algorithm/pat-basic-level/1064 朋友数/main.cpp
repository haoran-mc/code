// 260303 09:03 Tue
#include <iostream>
#include <set>
using namespace std;
set<int> st;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        int res = 0;
        while (a) {
            res += a % 10;
            a /= 10;
        }
        st.insert(res);
    }
    cout << st.size() << endl;
    bool isFirst = true;
    for (auto it = st.begin(); it != st.end(); it++) {
        if (isFirst) {
            cout << *it;
            isFirst = false;
        } else {
            cout << " " << *it;
        }
    }
    return 0;
}
