#include <algorithm>
#include <bits/stdc++.h>
#include "../common.hpp"

int n,m;

struct edge{
    int val,x,y;
};

bool com(const edge& a,const edge& b){
    return a.val > b.val;
}

int a[20005],b[20005];
edge f[100005];

int find(int x){
    if(a[x] == x){
        return x;
    } else {
        return find(a[x]);
    }
}

void add(int x,int y){
    int u = find(x);
    int v = find(y);
    a[u] = v;
}

bool check(int x,int y){
    int u = find(x);
    int v = find(y);
    if(u == v) return true;
    return false;
}


void solution(){
    cin>>n>>m;
    for(int i = 1;i <= n;i++) a[i] = i;
    for(int i = 1;i <= m;i++){
        cin>>f[i].x>>f[i].y>>f[i].val;
    }
    sort(f+1,f+1+m,com);

    for(int i = 1;i <= m+1;i++){
        if(check(f[i].x,f[i].y)){
            cout<<f[i].val<<endl;
            return;
        } else{
            if(!b[f[i].x]) b[f[i].x] = f[i].y;
            else add(b[f[i].x], f[i].y);

            if(!b[f[i].y]) b[f[i].y] = f[i].x;
            else add(b[f[i].y],f[i].x);
        }
    }
}


