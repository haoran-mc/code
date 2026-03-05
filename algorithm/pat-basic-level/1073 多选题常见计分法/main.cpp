// 260305 10:03 Thu
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool cmp1(pair<char, int> p1, pair<char, int> p2) {
    return p1.first < p2.first;
}

bool cmp2(pair<char, int> p1, pair<char, int> p2) {
    return p1.second < p2.second;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<double> max(m), score(n);    // max记录每道题分值，score记录每位先生得分
    vector<unordered_set<char>> ans(m); // 记录每道题答案
    for (int i = 0; i < m; i++) {
        int num_option, num_answer;
        char c;
        cin >> max[i] >> num_option >> num_answer;
        for (int j = 0; j < num_answer; j++) {
            cin >> c;
            ans[i].insert(c);
        }
    }
    vector<unordered_map<char, int>> mis(m); // 题号、选项、错误次数
    for (int i = 0; i < n; i++) {
        getchar();
        for (int j = 0; j < m; j++) {
            int num;
            scanf("(%d", &num);
            unordered_set<char> set;
            int flag = 1;
            for (int k = 0; k < num; k++) {
                char c;
                cin >> c;
                set.insert(c);
                if (ans[j].find(c) == ans[j].end()) {
                    flag = 0;
                    mis[j][c]++;
                }
            }
            getchar();
            if (j != m - 1)
                getchar();
            if (ans[j] == set) {
                score[i] += max[j];
            } else if (flag)
                score[i] += max[j] / 2;
            for (auto it : ans[j]) {
                if (set.find(it) == set.end()) {
                    mis[j][it]++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%.1f\n", score[i]);
    }
    int max_mis = 0;
    unordered_map<char, int> para;
    for (int i = 0; i < m; i++) {
        for (auto it : mis[i]) {
            if (it.second > max_mis) {
                para.clear();
                max_mis = it.second;
                para[it.first] = i + 1;
            } else if (it.second == max_mis) {
                para[it.first] = i + 1;
            }
        }
    }
    vector<pair<char, int>> vec(para.begin(), para.end());
    sort(vec.begin(), vec.end(), cmp1);
    sort(vec.begin(), vec.end(), cmp2);
    if (max_mis > 0) {
        for (auto it : vec) {
            cout << max_mis << " " << it.second << "-" << it.first << endl;
        }
    } else {
        cout<<"Too simple"<<endl;
    }
    return 0;
}
