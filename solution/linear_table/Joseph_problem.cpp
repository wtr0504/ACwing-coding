#include <bits/stdc++.h>
#include "../common.hpp"

bool visited[105];

void solution(){
    int m,n;
    cin>>n>>m;
    int k = 1;
    for(int i = 1;i <= n;i++){
        int j = m;
        while(j-1){
            while(visited[k]){
                k++;
                if(k > n) k = 1;
            }
            k++;
            if(k > n) k = 1;
            j--;
        }
        while(visited[k]){
            k++;
            if(k > n) k = 1;
        }
        visited[k] = true;
        cout<<k<<" ";
    }
}

