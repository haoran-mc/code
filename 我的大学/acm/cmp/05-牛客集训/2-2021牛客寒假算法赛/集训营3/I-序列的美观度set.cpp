#include <cstdio>
#include <unordered_set>
using namespace std;
unordered_set<int> unst;
int main() {
    int n;
    scanf("%d", &n);
    int pre;
    scanf("%d", &pre);
    int res = 0;
    for (int i = 0; i < n-1; ++i) {
        int num;
        scanf("%d", &num);
        if (num == pre) {
            unst.clear();
            ++res;
        }
        else {
            unst.insert(pre);
            if (unst.find(num) != unst.end()) {
                unst.clear();
                pre = num;
                ++res;
            }
            else {
                unst.insert(num);
                pre = num;
            }
        }
    }
    printf("%d\n", res);
    return 0;
}
