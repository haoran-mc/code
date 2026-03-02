#include <iostream>
#include <deque>
using namespace std;
const int maxn = 1e6 + 5;
struct Arr {
    int val;
    int idx;
} arr[maxn];
int n, k;

void getMin() {
    deque<Arr> dqu;
    for (int i = 0; i < k; ++i) {
        while (!dqu.empty() && arr[i].val <= dqu.back().val)
            dqu.pop_back();
        dqu.push_back(arr[i]);
    }
    cout << dqu.front().val;
    for (int i = k; i < n; ++i) {
        while (!dqu.empty() && arr[i].val <= dqu.back().val)
            dqu.pop_back();
        dqu.push_back(arr[i]);
        while (!dqu.empty() && dqu.front().idx <= arr[i].idx - k)
            dqu.pop_front();
        cout << " " << dqu.front().val;
    }
    cout << endl;
}

void getMax() {
    deque<Arr> dqu;
    for (int i = 0; i < k; ++i) {
        while (!dqu.empty() && arr[i].val >= dqu.back().val)
            dqu.pop_back();
        dqu.push_back(arr[i]);
    }
    cout << dqu.front().val;
    for (int i = k; i < n; ++i) {
        while (!dqu.empty() && arr[i].val >= dqu.back().val)
            dqu.pop_back();
        dqu.push_back(arr[i]);
        while (!dqu.empty() && dqu.front().idx <= arr[i].idx - k)
            dqu.pop_front();
        cout << " " << dqu.front().val;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        arr[i].idx = i;
        cin >> arr[i].val;
    }
    getMin();
    getMax();
    return 0;
}
