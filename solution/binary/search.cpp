#include "../common.hpp"
#include <algorithm>

#define ll long long

ll v[1000005];
ll s[100005];

int helper(ll target,int n){
    int l = 0,r = n - 1;
    while(l < r){
        int mid = (l + r) / 2;
        if(v[mid] >= target){
            r = mid;
        } else{
            l = mid + 1;
        }
    }
    if(v[l] == target) return l;
    return -2;
}


void search(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i < n;i++){
        cin>>v[i];
    }
    for(int i = 0;i < m;i++){
        cin>>s[i];
    }

    for(int i = 0;i < m;i++){
        cout<<helper(s[i],n) + 1;
        if(i != m - 1){
            cout<<" ";
        }
    }
    cout<<endl;
}

void solution(){
    search();
}