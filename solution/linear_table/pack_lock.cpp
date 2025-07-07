#include <bits/stdc++.h>
#include <map>
#include "../common.hpp"
#define ll long long

int n,q;
map<long long, int>m;

void solution(){
    cin>>n>>q;
    while(q--){
        int w,i,j,k;
        cin>>w;
        if(w == 1){
            cin>>i>>j>>k;
            m[i * 100000 + j] = k;
        } else{
            cin>>i>>j;
            cout<<m[i * 100000 + j]<<endl;
        }
    }
}