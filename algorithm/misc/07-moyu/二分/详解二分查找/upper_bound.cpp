#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int num[] = {0, 1, 1, 1, 1, 1, 2};
    int val = 1;
    int* lowerPos = lower_bound(num, num + 7, val);
    printf("%d\n", (int)(lowerPos - num));
    printf("%d\n", *lowerPos);

    int* upperPos = upper_bound(num, num + 7, val);
    printf("%d\n", (int)(upperPos - num));
    printf("%d\n", *upperPos);

    vector<int> vec;
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(2);
    vector<int>::iterator it;
    it = lower_bound(vec.begin(), vec.end(), val);
    printf("%d\n", (int)(it - vec.begin()));
    printf("%d\n", *it);

    it = upper_bound(vec.begin(), vec.end(), 2);
    printf("%d\n", (int)(it - vec.begin()));
    printf("%d\n", *it);

    return 0;
}

