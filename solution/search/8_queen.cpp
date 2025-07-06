#include "../common.hpp"
#include "algorithm"
#include <iostream>

int mat[14][14];
int path[14];
int n,cnt;

bool check(int x,int y){
    for(int i = 0;i < n;i++){
        if(mat[i][y] == 1){
            return false;
        }
    }
    for(int i = x - 1,j = y - 1;i >= 0 && j>=0;i--,j--){
        if(mat[i][j] == 1){
            return false;
        }
    }
    for(int i = x - 1,j = y + 1;i >= 0 && j < n;i--,j++){
        if(mat[i][j] == 1){
            return false;
        }
    }
    return true;
}

void helper(int row){
    if(row >= n){
        if(cnt++ < 3)
            for(int i = 0;i < n;i++){
                cout<<path[i];
                if(i != n-1){
                    cout<<" ";
                }
            }
        cout<<endl;
        return;
    }
    
    for(int j = 0;j < n;j++){
        if(check(row, j)){
            mat[row][j] = 1;
            path[row] = j + 1;
            helper(row+1);
            path[row] = 0;
            mat[row][j] = 0;
        }
    }
}

void solution(){
    cin>>n;
    helper(0);
    cout<<cnt<<endl;
}