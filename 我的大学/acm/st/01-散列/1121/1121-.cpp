#include <cstdio>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e6;
int couple[N];

int main()
{
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

    vector<int> single;
    for (unordered_set<int>::iterator it = st.begin(); it != st.end(); it++)
        if (couple[*it] == 0 || st.find(couple[*it]) == st.end())
            single.push_back(*it);

    if (single.empty()) {
        printf("0\n");
        return 0;
    }
    else
        printf("%d\n", (int)single.size());

    sort(single.begin(), single.end());
    for (int i = 0; i < (int)single.size(); i++) {
        if (i)
            printf(" ");
        printf("%05d", single[i]);
    }
    return 0;
}
