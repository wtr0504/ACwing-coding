#include <bits/stdc++.h>
#include "../common.hpp"



int f[100005];
int enemy[100005];
int t,n;


int find(int x){
    if(x == f[x]) return x;
    else return find(f[x]);
}

void add(int x,int y){
    int u = find(x);
    int v = find(y);
    a[u] = v;
}

void solution(){
    cin>>t;

    for(t--){
        cin>>n;
        for(int i = 1;i <= n;i++) f[i] = i;

        int x,y,c;
        for(int i = 1;i <= n;i++){
            cin>>x>>y>>c;
            if(c == 1){

            } else{
                if(enemy[x] == 0) enemy[x] = y;
                else add()
            }
        }

    }
}
