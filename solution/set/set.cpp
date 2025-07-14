#include <bits/stdc++.h>
#include "../common.hpp"

#define MAXN 105

int prime[MAXN],vis[MAXN],f[MAXN];
int a,b,p;

bool check(int x){
    if(x <= 1) return false;
    if(x == 2) return true;
    if(x % 2 == 0) return false;
    int p = static_cast<int>(sqrt(x));
    for(int i = 3;i <= p;i++){
        if(x % i == 0) return false;
    }
    return true;
}


void make_prime(){
    int i = 1;
    for(;i <= b;i++){
        if(check(i)) prime[i] = 1;
        else prime[i] = 0;
    }
}

int find(int x){
    if(x == f[x]){
        return x;
    } else {
        return find(f[x]);
    }
}

void add(int x,int y){
    int u = find(x);
    int v = find(y);
    if(u != v){
        f[u] = v;
    }
}

int cnt;
void solution(){
    cin>>a>>b>>p;
    for(int i = a; i <= b;i++) f[i] = i;
    make_prime();
    for(int i = p;i <= b;i++){
        if(prime[i] == 1)
            vis[++cnt] = i;
    }
    for(int i = 1;i <= cnt;i++){
        int cc = 0;
        while(cc * vis[i] < a) cc++;
        while((cc+1) * vis[i] <= b){
            add(cc * vis[i],(cc+1) * vis[i]);
            cc++;
        }
    }
    int res = 0;
    for(int i = a;i <= b;i++){
        if(f[i] == i) res++;
    }
    cout<<res<<endl;
}




