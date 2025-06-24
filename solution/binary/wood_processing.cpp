#include "../common.hpp"

#define ll long long
ll woods[100005];
ll n,k;
bool f(ll x){
    ll res = 0;
    for(int i = 0;i < n;i++){
        res += woods[i] / x;
    }
    return res >= k;
}

void wood_processing(){
    cin>>n>>k;
    for(int i = 0;i < n;i++) cin>>woods[i];

    int l = 0,r = 1e8 + 1;
    while(l + 1 < r){
        ll mid = (l + r) / 2;
        if(f(mid)){
            l = mid;
        } else {
            r = mid;
        }
    }
    cout<< l <<endl;
}

void solution(){
    wood_processing();
}