#include <bits/stdc++.h>
#include "../common.hpp"


int n,res;
set<int> s;

void solution(){
    cin>>n;
    for(int i = 0;i < n;i++){
        int k;
        cin>>k;
        if(i == 0){
            res += k;
            s.emplace(k);
        } else{
            auto idx = s.lower_bound(k);
            if(*idx != k){
                auto j = idx;
                j--;
                res += min(abs(k - *idx),abs(k - *j));
            }
        }
    }
    cout<<res<<endl;
}