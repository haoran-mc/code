#include <cstdio>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

const int N = 1e6;
int couple[N];
vector<int> single;

int main()
{
    fill(couple, couple + N, -1);
    int n;
    scanf("%d", &n);
    while (n--) {
        int couple1;
        int couple2;
        scanf("%d", &couple1);
        scanf("%d", &couple2);
        couple[couple1] = couple2;
        couple[couple2] = couple1;
    }

    int k;
    scanf("%d", &k);
    unordered_set<int> st;
    while (k--) {
        int x;
        scanf("%d", &x);
        st.insert(x);
    }

    for (unordered_set<int>::iterator it = st.begin(); it != st.end(); it++)
        if (couple[*it] == -1 || st.find(couple[*it]) == st.end())
            single.push_back(*it);

    if (single.size() == 0) {
        printf("0\n");
        return 0;
    }
    else
        printf("%d\n", (int)single.size());

    sort(single.begin(), single.end());
    for (vector<int>::iterator it = single.begin(); it != single.end(); it++) {
        if (it == single.begin()) {
            printf("%05d", *it);
            continue;
        }
        printf(" %05d", *it);
    }
    return 0;
}
