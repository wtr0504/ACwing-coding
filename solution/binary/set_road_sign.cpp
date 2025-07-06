#include "../common.hpp"
#define ll long long
ll L,K,N;
ll signs[100005];

bool f(ll x){
    int cnt = 0;
    for(int i = 1;i < N;i++){
        cnt += (signs[i] - signs[i-1] - 1) / x;
    } 
    // if(L - pos < x) cnt++
    return cnt > K;
}


void solution(){
    cin>>L>>N>>K;
    if(K == 0){
        cout<< L<<endl;;
    }
    for(int i = 0;i < N;i++) cin>>signs[i];

    ll l = 1,r = signs[N - 1];
    while(l <= r){
        int mid = (l + r) / 2;
        if(f(mid)){
            l = mid + 1;
        } else{
            r = mid - 1;
        }
    }
    cout<<r + 1<<endl;
}