#include "../common.hpp"
#include <bits/stdc++.h>
#include <iterator>
#include <queue>

#define MAX_N 100005
#define MAX_M 500005
class edge{
    public:
    int to,dis,next;
};

int head[MAX_N],dis[MAX_N],cnt;
int visited[MAX_N];
edge e[MAX_M];
int n,m,s;

void add_adge(int u,int v,int d){
    cnt++;
    e[cnt].to = v;
    e[cnt].dis = d;
    e[cnt].next = head[u];
    head[u] = cnt;
}

struct node{
    int dis;
    int pos;
    bool operator <(const node &n) const{
        return n.dis < dis;
    }
};

void dijkstra(){
    priority_queue<node> pq;
    pq.push({0,s});

    while(!pq.empty()){
        node tmp = pq.top();
        int d = tmp.dis;
        int x = tmp.pos;
        pq.pop();
        if(visited[x])
            continue;
        visited[x] = true;
        for(int i = head[x];i;i = e[i].next){
            int y = e[i].to;
            if(dis[y] > dis[x] + e[i].dis){
                dis[y] = dis[x] + e[i].dis;
                if(!visited[y])
                    pq.push({dis[y],y});
            }
        }
    }
    
}

void solution(){
    cin>>n>>m>>s;
    for(int i = 1;i <= n;i++) dis[i] = INT_MAX;
    for(int i = 1;i <= m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add_adge(u,v,w);
    }
    dis[s] = 0;
    dijkstra();
    for(int i = 1;i <= n;i++){
        cout<<dis[i];
        if(i != n)
            cout<<" ";
    }
    cout<<endl;

}
