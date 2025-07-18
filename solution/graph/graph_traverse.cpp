#include <bits/stdc++.h>
#include <vector>
#include "../common.hpp"



int n,m;
vector<vector<int>> g(100005);
int res[100005];


void dfs(int x,int d){
    if(res[x]) return ;
    res[x] = d;
    for(int i = 0;i < g[x].size();i++){
        dfs(g[x][i],d);
    }
}



void solution(){
    cin>>n>>m;
    int x,y;
    for(int i = 0;i < m;i++){
        cin>>x>>y;
        g[y].push_back(x);
    }

    for(int i = n;i >= 1;i--) dfs(i,i);

    for(int i = 1;i <= n;i++)
        cout<<res[i]<<" ";
    cout<<endl;
}


