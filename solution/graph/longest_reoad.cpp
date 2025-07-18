#include <bits/stdc++.h>
#include <functional>
#include <variant>
#include <vector>

using namespace std;

int head[1505];
int d[1505],in[1505];
bool visited[1505];
int n,m;

struct edge{
    int u,v;
    int w;
    int next;
};
int cnt;
edge g[50005];

void add(int u,int v,int w){
    g[++cnt] = {u,v,w};
    g[cnt].next = head[u];
    head[u] = cnt;
    in[v]++;
}

struct node{
    int pos,w;
    bool operator <(const node& x) const{
        return this->w > x.w;
    }
};

queue<int> q;

void topo(){
    // q.push(1);
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0)
            q.push(i);
    }


    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = head[u];i;i = g[i].next){
            int v = g[i].v;
            int w = g[i].w;
            if(d[v] < d[u] + w){
                d[v] = d[u] + w;
            }
            in[v]--;
            if(in[v] == 0)
                q.push({v});
        }
    }
}


void solution(){
    cin>>n>>m;
    memset(d, -0x3f, sizeof(d));
    d[1] = 0;

    for(int i = 1;i <= m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add(u, v,  w);
    }
    topo();
    cout<<d[n]<<endl;
}

