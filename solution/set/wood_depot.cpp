#include <bits/stdc++.h>
#include <map>
#include "../common.hpp"

set<int> s;
int n;


void add(int x){
    if(s.find(x) != s.end()){
        cout<<"Already Exist"<<endl;
    } else {
        s.emplace(x);
    }
}

int rm(int x){
    auto ld = s.lower_bound(x);
    auto rd = s.upper_bound(x);
    auto i = ld;
    if(ld != s.begin())i--;
    int res = 0;
    if(s.empty()) return 0;
    if(ld != s.end() && *ld == x){
        s.erase(x);
        return x;
    } else{
        if(rd != s.end()){
            if(x - *i > *rd - x){
                res = *rd;
                s.erase(res);return res;
            }else if (x -  *i <= *rd - x){
                res = *i;
                s.erase(res);
                return res;
            }
        } else {
            res = *i;
            s.erase(res);  
            return res;
        }
    }
    return res;
}


void solution(){
    cin>>n;
    for(int i = 0;i < n;i++){
        int o,x;
        cin>>o>>x;
        if(o == 1){
            add(x);
        } else{
            int r = rm(x);
            if(r == 0) cout<<"Empty"<<endl;
            else cout<<r<<endl;
        }
    }

}