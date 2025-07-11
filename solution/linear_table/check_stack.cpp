#include <bits/stdc++.h>
#include "../common.hpp"

int pushed[15],poped[15];
int p1,p2;

stack<int> stk;
int q;

void solution(){
    
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        p1 = 0;
        p2 = 0;
        for(int i = 0;i < n;i++) cin>>pushed[i];
        for(int i = 0;i < n;i++) cin>>poped[i];

        while(p1 < n){
            stk.push(pushed[p1++]);
            while(stk.top() == poped[p2]){
                p2++;
                stk.pop();
                if(stk.empty()) break;
            }
        }
        if(stk.empty()){
            cout<<"Yes"<<endl;
        } else{
            cout<<"No"<<endl;
        }
        while(!stk.empty())stk.pop();
    }
}