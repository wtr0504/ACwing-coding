#include <bits/stdc++.h>
#include "../common.hpp"

#define N 102
int n;
char mat[N][N];
char res[N][N];
int step;
string p = "yizhong";

int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8] = {1,-1,0,1,-1,0,1,-1};

bool check(int x,int y){
    return x >= 0 && x < n && y >= 0 && y < n && mat[x][y] == p[step];
}

bool dfs(int dir,int x,int y){
    if(step >= p.size()){
        return true;
    }
    int n_x = x + dx[dir];
    int n_y = y + dy[dir];
    if(check(n_x, n_y)){
        step++;
        if(dfs(dir,n_x,n_y)){
            res[n_x][n_y] = p[step-1];
            step--;
            return true;
        }
        step--;
    }
    return false;
}


void solution(){
    cin>>n;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            cin>>mat[i][j];
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(mat[i][j] == 'y'){
                step++;
                for(int k = 0;k < 8;k++)
                    if(dfs(k,i,j))
                        res[i][j] = 'y';
                step--;
            }
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(res[i][j] >= 'a' && res[i][j] <= 'z'){
                cout<<res[i][j];
            } else{
                cout<<'*';
            }
        }
        cout<<endl;
    }
}