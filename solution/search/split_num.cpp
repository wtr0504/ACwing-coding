#include <bits/stdc++.h>
#include "../common.hpp"

int n;
int path[10];
int e;
int sum;

void p(){
    for(int i = 0;i < e;i++){
        cout<<path[i];
        if(i != e-1)
            cout<<"+";
    }
    cout<<endl;
}

void dfs(int start){
    if(sum > n) return;
    if(sum == n){
        p();
    }
    for(int i = start;i < n;i++){
        sum += i;
        path[e++] = i;
        dfs(i);
        sum -= i;
        e--;
    }
}

void solution(){
    cin>>n;
    dfs(1);
}