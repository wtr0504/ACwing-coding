#include <bits/stdc++.h>
#include <cstring>
#include <vector>
#include "../common.hpp"


vector<vector<int>> graph(1005);
int k,n,m;
int cows[105];
int visited[1005];


void dfs(int u){
    visited[u]++;
    if(graph[u].empty()){
        return;
    }
    for(int i = 0;i < graph[u].size();i++){
        if(!visited[graph[u][i]])
            dfs(graph[u][i]);
    }
}
int res;

void solution(){
    cin>>k>>n>>m;
    for(int i = 1;i <= k;i++) cin>>cows[i];
    for(int i = 1;i <= m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    for(int i = 1;i <= k;i++){
        memset(visited + 1, 0, n);
        dfs(cows[i]);
    }
    for(int i = 1;i <= n;i++){
        if(visited[i] == k){
            res++;
        }
    }
    cout<<res<<endl;
}