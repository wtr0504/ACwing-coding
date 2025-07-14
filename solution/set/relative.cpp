#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "../common.hpp"


int father[5005];
int n,m,p;

int find(int x){
    if(x == father[x]){
        return x;
    } else {
        return find(father[x]);
    }
}

void solution(){
    cin>>n>>m>>p;
    for(int i = 0;i < n;i++) father[i] = i;

    for(int i = 1;i <= m;i++){
        int x,y;
        cin>>x>>y;
        int u = find(x),v = find(y);
        if(u != v) father[u] = v;
    }

    for(int i = 0;i < p;i++){
        int x,y;
        cin>>x>>y;
        if(find(x) != find(y)){
            cout<<"No"<<endl;
        } else {
            cout<<"Yes"<<endl;
        }
    }
}