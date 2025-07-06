#include <bits/stdc++.h>
#include <climits>
#include "../common.hpp"


class edge{
    public:
    int to;
    int dis;
    int next;
};

edge e[405];
int n,a,b;
int cnt;
int dis[205];
int head[205];
bool visited[205];

void add_adge(int u,int v,int w){
    if(v <= 0 || v > 200) return;
    cnt++;
    e[cnt].to = v;
    e[cnt].dis = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}

struct node{
    int dis;
    int pos;
    bool operator <(const node& x) const{
        return x.dis < dis;
    }
};

void dijkstra(){
    dis[a] = 0;
    priority_queue<node> q;
    q.push({0,a});

    while(!q.empty()){
        node tmp = q.top();
        q.pop();
        int w = tmp.dis;
        int x = tmp.pos;
        if(visited[x])
            continue;
        visited[x] = true;
        for(int i = head[x];i;i = e[i].next){
            int y = e[i].to;
            if(dis[y] > dis[x] + e[i].dis){
                dis[y] = dis[x] + e[i].dis;
                if(!visited[y])
                    q.push({dis[y],y});
            }
        }
    }
}


void  solution(){
    cin>>n>>a>>b;
    for(int i = 1;i <= n;i++)dis[i] = INT_MAX;
    for(int i = 1;i <= n;i++){
        int w;
        cin>>w;
        add_adge(i, i + w, 1);
        add_adge(i, i - w, 1);
    }
    dijkstra();
    if(dis[b] == INT_MAX){
        cout<<"-1"<<endl;
        return;
    }
    cout<<dis[b]<<endl;
}




