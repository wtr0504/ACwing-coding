#include <algorithm>
#include <bits/stdc++.h>
#include "../common.hpp"


#define ull unsigned long long



ull hh(const string &s) {
    const ull P = 131;
    const ull MOD = 1e9 + 7;
    ull h = 0;
    for (char c : s) {
        h = (h * P + c) % MOD;
    }
    return h;
}


ull a[10005];
int n;

bool check(ull h){
    for(int i = 0;i < n;i++){
        if(a[i] == h) return true;
    }
    return false;
}

void solution(){
    cin>>n;
    int res = 0;
    for(int i = 0;i < n;i++){
        string s;
        cin>>s;
        ull h = hh(s);
        // while(check(h)) h += 19260817;
        a[i] = h;
    }
    sort(a,a+n);

    for(int i = 1;i < n;i++){
        if(a[i] != a[i-1]){
            res++;
        }
    }
    cout<<res+1<<endl;
}