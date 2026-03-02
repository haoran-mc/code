#include <cstdio>
#include <set>
using namespace std;
set<int> st;
int main() {
    st.insert(1);
    st.insert(1);
    for (auto it = st.begin(); it != st.end(); ++it)
        printf("%d\n", *it);
    printf("%d\n", '9' - '0');
    return 0;
}
