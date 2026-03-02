#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1e6 + 5;
vector<int> sequ;

bool judge(vector<int>::iterator it) {
    if (*it != *(it-1) && *it != *(it+1))
        return false;
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        sequ.push_back(num);
    }
    for (auto it = sequ.begin()+2; it != sequ.end(); ++it)
        if (!judge(it-1) && !judge(it)) {
            if (*(it-1) == *(it+1))
                sequ.erase(it);
            else
                sequ.erase(it-1);
        }
    int res = 0;
    for (auto it = sequ.begin()+1; it != sequ.end(); ++it)
        if (*(it-1) == *it)
            ++res;
    printf("%d\n", res);
    return 0;
}
