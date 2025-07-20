#include <cstring>
#include <iostream>

using namespace std;

const int INF = 0x3f3f3f3f;
struct edge{
    int u,v,w;
};

edge e[100005];
int d[505];
int back[505];
int n,m,k;



void bellman_ford(){
    d[1] = 0;
    for(int i = 0;i < k;i++){
        memcpy(back,d,sizeof(d));
        for(int j = 0;j < m;j++){
            int u = e[j].u,v = e[j].v,w = e[j].w;
            d[v] = min(d[v],back[u] + w);
        }
    }
}

void solution(){
    cin>>n>>m>>k;

    for(int i = 0;i < m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    memset(d,0x3f,sizeof(d));
    bellman_ford();
    if(d[n] > 0x3f3f3f3f /2){
        cout<<"impossible"<<endl;
    } else {
        cout<<d[n]<<endl;
    }
}



