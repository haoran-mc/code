#include <cstdio>
#include <stack>
using namespace std;
const int maxn = 1e3 + 5;
stack<int> sta;   // 推送器
stack<int> box;   // 盒子
stack<int> cur;   // 松枝
stack<int> tmp;
int store[maxn];
// 推送器上松针片的数量
// 小盒子存放最大数量
// 松枝干上松针片最大数量
int n, m, k;
int idx = 0;

void reve() {
    while (!sta.empty()) {
        store[idx ++ ] = sta.top();
        sta.pop();
    }
    for (int i = 0; i < idx; i ++ )
        sta.push(store[i]);
}

void output() {
    while (!cur.empty()) {
        int t = cur.top();
        cur.pop();
        tmp.push(t);
    }
    bool fi = false;
    while (!tmp.empty()) {
        int t = tmp.top();
        tmp.pop();
        if (!fi) {
            printf("%d", t);
            fi = true;
        }
        else
            printf(" %d", t);
    }
    puts("");
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i ++ ) {
        int a; scanf("%d", &a);
        sta.push(a);
    }
    reve();
    while (true) {
        while (true) {
            if (cur.size() >= k) {  // 制作下一根
                output();
                break;
            }
            // 继续制作
            if (!box.empty()) {   // 如果盒子里还有，优先选择盒子里的
                if (cur.empty()) {
                    cur.push(box.top());
                    box.pop();
                    continue;
                } else if (box.top() <= cur.top()) {
                    cur.push(box.top());
                    box.pop();
                    continue;
                } else if (box.top() > cur.top()) {   // 选择推送器
                    if (!sta.empty()) {
                        if (sta.top() > cur.top() && box.size() < m) {
                            box.push(sta.top());
                            sta.pop();
                            continue;
                        } else if (sta.top() > cur.top() && box.size() >= m) {
                            output();
                            break;
                        } else if (sta.top() <= cur.top()) {
                            cur.push(sta.top());
                            sta.pop();
                            continue;
                        }
                    } else {   // 推送器空
                        output();
                        break;
                    }
                }
            } else {
                if (!sta.empty()) {
                    if (cur.empty()) {
                        cur.push(sta.top());
                        sta.pop();
                    } else if (sta.top() > cur.top() && box.size() < m) {
                        box.push(sta.top());
                        sta.pop();
                        continue;
                    } else if (sta.top() <= cur.top()) {
                        cur.push(sta.top());
                        sta.pop();
                        continue;
                    }
                } else {   // 推送器空
                    output();
                    break;
                }
            }
        }
        if (box.empty() && sta.empty())
            break;
    }
    return 0;
}