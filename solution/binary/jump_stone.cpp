#include "../common.hpp"
#include <iostream>

#define ll long long

int n,m,L;
ll stones[50005];
bool f(ll x){
    ll cnt = 0,pos = 0;
    for(int i = 0;i < n;i++){
        if(stones[i] - pos <x){
            cnt++;
        } else{
            pos = stones[i];
        }
    }
    if (L - pos < x) cnt++;
    return cnt <= m;
}

void solution(){
    cin>>L>>n>>m;
    if(n == 0 && m == 0){
        cout<<L<<endl;
        return;
    }
    for(int i = 0;i < n;i++) cin>>stones[i];
    ll l = 0,r = L;
    while(l < r){
        int mid = (l + r) / 2;
        if(f(mid)){
            l = mid + 1;
        } else{
            r = mid;
        }
    }
    cout<<l - 1<<endl;
}

