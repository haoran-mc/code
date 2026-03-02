#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
typedef pair<int,int> PII;
const int N=200100,INF=0x3f3f3f3f;

int h[N],ne[N],w[N],e[N],idx;
int n,m;
int dist[N];
bool st[N];
int route[N];
int teams[N];
int gather[N];
int source;
int save;

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void dijkstra(){
    memset(dist,0x3f,sizeof dist);
    memset(st, 0, sizeof(st));
    memset(route, 0, sizeof(route));
    dist[source] = 0;
    route[source] = 1;
    priority_queue<PII, vector<PII>, greater<PII>>  heap;
    heap.push({0,source});
    while(!heap.empty()){
        auto t=heap.top();
        heap.pop();
        int ver=t.second,distance=t.first;
        if(st[ver]) continue;
        st[ver]=true;
        for(int i=h[ver];~i;i=ne[i]){
            int j=e[i];
            if(dist[j]>distance+w[i]){
                dist[j]=distance+w[i];
                gather[j] = gather[ver] + distance;
                route[j] = route[ver];
                heap.push({dist[j],j});
            }
            else if (dist[j] == dist[ver] + distance) {
                route[j] += route[ver];
                if (gather[j] < gather[ver] + teams[j])
                    gather[j] = gather[ver] + teams[j];
            }
        }
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin.tie(0);
    cin>>n>>m;
    cin >> source >> save;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &teams[i]);
        gather[i] = teams[i];
    }
    memset(h,-1,sizeof h);
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    cout << route[save] << " " << gather[save];
    return 0;
}
