#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define bug printf("<------>\n");

struct gasStation {
    int dist;
    int cost;
};

bool cmp(gasStation A, gasStation B) {
    return A.dist < B.dist;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    int L, P;
    scanf("%d %d", &L, &P);
    vector<gasStation> station;
    gasStation End;
    End.dist = L;
    End.cost = 0;
    station.push_back(End);
    for (int i = 0; i < n; ++i) {
        gasStation tem;
        scanf("%d %d", &tem.dist, &tem.cost);
        station.push_back(tem);
        //scanf("%d %d", &station[i].dist, &station[i].cost);
    }
    sort(station.begin(), station.end(), cmp);
    /*
     *for (auto it = station.begin(); it != station.end(); ++it)
     *    printf("%d %d\n", it -> dist, it -> cost);
     */
    if (station[0].dist > P) {
        printf("-1");
        return 0;
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pqu1;
    int i = 0;
    while (station[i++].dist < P)
        pqu1.push(make_pair(station[i-1].cost, station[i-1].dist));
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pqu2;
    i = 0;
    while (station[i++].dist < L)
        pqu2.push(make_pair(station[i-1].cost, station[i-1].dist));
    pair<int, int> get1 = pqu1.top();
    pair<int, int> get2 = pqu2.top();
    int pay = 0;
    pay += get1.first * (get2.second - get1.second - (P - get1.second));
    pay += get2.first * (L - get2.second);
    printf("%d", pay);
    return 0;
}
