#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include "../common.hpp"


int res[10005];
int n;

// void bfs(){
//     int x;
//     queue<int> q;
//     q.push(1);
//     res[1] = a[1];
//     while(!q.empty()){
//         x = q.front();
//         q.pop();
//         for(int i = 0;i < g[x].size();i++){
//             res[g[x][i]] = max(res[g[x][i]],a[g[x][i]] + res[x]);
//             q.push(g[x][i]);
//         }
//     }
// }

void solution(){
    cin>>n;
    int x,t,dep;
    for(int i = 1;i <= n;i++){
        cin>>x>>t;
        cin>>dep;
        int tmp = 0;
        while(dep != 0){
            tmp = max(tmp,res[dep]);
            cin>>dep;
        }
        res[x] = t + tmp;

    }
    cout<<*max_element(res+1,res + n+1)<<endl;;

}

