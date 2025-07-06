#include "../common.hpp"
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>

int mat[405][405];

int x,y,n,m;
int dx[8] = {1,1,2,2,-1,-1,-2,-2};
int dy[8] = {2,-2,1,-1,2,-2,1,-1};
int cnt;
int signs[405][405];

bool check(int x,int y){
    if(signs[x][y] == 1)
        return false;
    if(x >= 0 && x < n && y >= 0 && y < m)
        return true;
    return false;
}


void helper(int i,int j,int step){
    queue<pair<int,int>> q;
    q.push({i,j});
    while(!q.empty()){
        i = q.front().first;
        j = q.front().second;
        q.pop();
        for(int k = 0;k < 8;k++){
            int n_x = i + dx[k];
            int n_y = j + dy[k];
            if(check(n_x, n_y)){
                q.push({n_x,n_y});
                mat[n_x][n_y] = mat[i][j] + 1;
                signs[n_x][n_y] = 1;
            }
        }
        // step++;
    }   
}

void solution(){
    cin>>n>>m>>x>>y;
    for (int i = 0; i < 405; ++i) {
        for (int j = 0; j < 405; ++j) {
            mat[i][j] = -1;
        }
    }
    mat[x-1][y-1] = 0;
    signs[x-1][y-1] = 1;
    helper(x-1, y-1,0);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            
            cout<<mat[i][j];
            if(j != m-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

