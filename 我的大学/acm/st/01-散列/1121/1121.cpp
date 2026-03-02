#include <cstdio>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

#define N 100005
int couple[N];

int main(){
    int n;
    scanf("%d", &n);
    fill(couple, couple+N, -1);
    for (int i = 0; i < n; i++) {
        int a;
        int b;
        scanf("%d %d", &a, &b);
        couple[a] = b;
        couple[b] = a;
    }

    int k;
    scanf("%d", &k);
    unordered_set<int> st;
    for (int i = 0; i < k; i++) {
        int a;
        scanf("%d", &a);
        st.insert(a);
    }

    vector<int> dog;
    for (auto it = st.begin(); it != st.end(); it++)
        if (couple[*it] < 0 || st.find(couple[*it]) == st.end())
            dog.push_back(*it);

    if (dog.empty()) {
        printf("0\n");
        return 0;
    }
    else
        printf("%d\n", (int)dog.size());

    sort(dog.begin(), dog.end());
    for (int i = 0; i < (int)dog.size(); i++) {
        if (i)
            printf(" ");
        printf("%05d", dog[i]);
    }
    return 0;
}
