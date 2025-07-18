#include <bits/stdc++.h>
#include "../common.hpp"

int a[50005];
int cnt;


unordered_set<int> s;
int t;


void solution(){
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cnt = 0;
        for(int i = 0;i < n;i++){
            int k;
            cin>>k;
            if(s.find(k) != s.end()){
                continue;
            } else{
                a[cnt++] = k;
                s.insert(k);
            }
        }
        s.clear();
        for(int i = 0;i < cnt;i++){
            cout<<a[i];
        }
        cout<<endl;
    }
}