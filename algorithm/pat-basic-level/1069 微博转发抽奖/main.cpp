// 260304 13:03 Wed
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
set<string> st;
vector<string> vec;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int M, N, S;
    cin >> M >> N >> S;

    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        vec.push_back(str);
    }

    int f = 0;
    for (int i = S - 1, j = N; i < M; i++, j++) {
        if (j == N) {
            if (st.count(vec[i]) == 0) {
                j = 0;
                st.insert(vec[i]);
                f = 1;
                cout << vec[i] << endl;
            } else {
                j--;
            }
        }
    }

    if (f == 0) {
        cout << "Keep going..." << endl;
    }
    return 0;
}
