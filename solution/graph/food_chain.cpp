#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000001

#define MOD(x) (x % 80112002)

int d[MAX_N],in[MAX_N],eat[MAX_N],head[MAX_N];
int n,m,a,b;
int cnt,res;

struct edge{
    int to,next;
};

edge e[5000005];

void add(int u,int v){
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}
queue<int> q;
void topo(){
    for(int i = 1;i <= n;i++){
        if(in[i] == 0){
            q.push(i);
            d[i] = 1;
        }
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = head[x];i;i = e[i].next){
            int y = e[i].to;
            d[y] = (d[y] + d[x])% 80112002;
            in[y]--;
            if(in[y] == 0)
                q.push(y);
        }
    }
}

void solution(){
    cin>>n>>m;
    for(int i = 1;i <= m;i++){
        cin>>a>>b;
        add(a,b);
        in[b]++;
        eat[a]++;
    }
    topo();

    for(int i = 1;i <= n;i++){
        if(eat[i] == 0){
            res = (res + d[i]) % 80112002;
        }
    }

    cout<<res<<endl;
}

int main(){
    solution();
    return 0;
}