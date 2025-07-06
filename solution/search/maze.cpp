#include <bits/stdc++.h>
#include "../common.hpp"

int n,m,t;
int dp[7][7];
bool visited[7][7];
int sx,sy,fx,fy;
int step;
int res;
int dir[4][4] = {{1,0},{-1,0},{0,1},{0,-1}};

bool check(int x,int y){
    return x >= 1 && x <= n && y >= 1 && y <= m && visited[x][y] == false && dp[x][y] != -1; 
}

void dfs(int x,int y){
    if(x == fx && y == fy){
        res++;
        return;
    }
    
    for(int i = 0;i < 4;i++){
        int n_x = x + dir[i][0];
        int n_y = y + dir[i][1];
        if(check(n_x, n_y)){
            visited[n_x][n_y] = true;
            dfs(n_x, n_y);
            visited[n_x][n_y] = false;
        }
    }
    
}


void solution(){
    cin>>n>>m>>t;
    cin>>sx>>sy>>fx>>fy;
    for(int i = 1;i <= t;i++){
        int x,y;
        cin>>x>>y;
        dp[x][y] = -1;
    }
    visited[sx][sy] = true;
    dfs(sx,sy);
    cout<<res<<endl;
    return;

}







