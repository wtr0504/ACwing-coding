#include "../common.hpp"
#define ll long long

ll N,M;
ll nums[100005];

bool f(ll x){
    ll res = 0;
    ll cnt = 0;
    for(int i = 0;i < N;i++){
        if(nums[i] + res <= x){
            res += nums[i];
        } else {
            res = nums[i];
            cnt++;
        }
    }
    return cnt >= M;
}


void solution(){
    cin>>N>>M;
    ll sum = 0;
    ll l = 0,r = sum;
    for(int i = 0;i < N;i++){
        cin>>nums[i];
        r += nums[i];
        l = max(l,nums[i]);
    } 
    while(l <= r){
        int mid = (l + r) >> 1;
        if(f(mid)){
            l = mid + 1;
        } else{
            r = mid - 1;
        }
    }
    cout<<l<<endl;
}





