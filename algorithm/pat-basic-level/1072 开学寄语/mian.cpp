// 260305 09:03 Thu
// 260305 09:54 Thu
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
unordered_set<int> st;

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        st.insert(a);
    }

    int res_stu = 0, res_thing = 0;
    for (int i = 0; i < N; i++) {
        string stu;
        int n;
        cin >> stu >> n;

        bool isFirst = true;
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            if (st.count(a) != 0) {
                if (isFirst) {
                    res_stu++;
                    // cout << stu << ": " << a;
                    printf("%s: %04d", stu.c_str(), a);
                    isFirst = false;
                } else {
                    // cout << " " << a;
                    printf(" %04d", a);
                }
                res_thing++;
            }
        }

        if (!isFirst)
            cout << endl;
    }

    cout << res_stu << " " << res_thing << endl;

    return 0;
}
