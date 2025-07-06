#include <bits/stdc++.h>
#include "../common.hpp"

#define N 23

string s[N];
int visited[N];
char c;
int n,res;


void dfs(string tmp){
    res = max(res,(int)tmp.size());
    for(int i = 0;i < n;i++){
        if(visited[i] >= 2) continue;
        for(int j = 1;j < min(s[i].size(),tmp.size());j++){
            if(tmp.substr(tmp.size() - j) == s[i].substr(0,j)){
                visited[i]++;
                dfs(tmp + s[i].substr(j));
                visited[i]--;
            }
        }
    }
}


void solution(){
    cin>>n;
    for(int i = 0;i < n;i++)cin>>s[i];
    cin>>c;
    for(int i = 0;i < n;i++){
        if(s[i][0] == c){
            visited[i]++;
            dfs(s[i]);
            visited[i]--;
        }
    }
    cout<<res<<endl;
}
