#include <bits/stdc++.h>
#include "../common.hpp"


int n,m;
int father[1005];

int find(int x){
    if(x == father[x]){
        return x;
    } else{
        return find(father[x]);
    }
}

void unity(int x,int y){
    int u = find(x);
    int v = find(y);
    father[u] = v;
}
int res;
void solution(){
    while(true){
        cin>>n;
        res = 0;
        if(!n) return;
        for(int i = 1; i <= n;i++) father[i] = i;
        cin>>m;
        for(int i = 0;i < m;i++){
            int x,y;
            cin>>x>>y;
            unity(x, y);
        }

        for(int i = 1;i <= n;i++){
            if(father[i] == i){
                res++;
            }
        }
        cout<<res-1<<endl;
    }
}