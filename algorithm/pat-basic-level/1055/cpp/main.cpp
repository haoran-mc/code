#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    string name; // 姓名
    int height;  // 身高
};

bool cmp(Node a, Node b) {
    if (a.height != b.height) {
        return a.height > b.height;
    } else
        return a.name < b.name;
}

int main() {
    Node n;
    int N, K;
    cin >> N >> K;
    vector<Node> v(N);
    for (int i = 0; i < N; i++) {
        cin >> n.name >> n.height;
        v[i] = n;
    }
    sort(v.begin(), v.end(), cmp);
    int row = K; // 第几排
    int t = 0;   // 代表输出到哪个了
    int m;       // 代表当前排的人数
    while (row) {
        if (row == K) { // 当时最后一排时要特殊处理，因为多出来的的人全站在最后一排
            m = N - N / K * (K - 1);
        } else { // 除了最后一排的其他情况
            m = N / K;
        }
        vector<string> name(m); // 现将当前排的情况建立一个数组，然后存到数组中在输出
        name[m / 2] = v[t].name;
        int j = m / 2 - 1;
        for (int i = t + 1; j >= 0; i += 2) { // 左侧
            name[j--] = v[i].name;
        }
        j = m / 2 + 1;
        for (int i = t + 2; j < m; i += 2) { // 右侧
            name[j++] = v[i].name;
        }
        cout<<name[0];
        for(int i=1;i<m;i++){
            cout<<" "<<name[i];
        }
        cout<<endl;
        t=t+m;
        row--;
    }
}
