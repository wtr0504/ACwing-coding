#include <iostream>
#include <algorithm>


int v,n;
int dp[20005];
int a[32];


void solution(){
    cin>>v>>n;
    for(int i = 1;i <= n;i++)cin>>a[i];

    for(int i = 1;i <= n;i++){
        for(int j = v; j >= a[i];j--){
            dp[j] = max(dp[j],dp[j - a[i]] + a[i]);
        }
    }
    cout<<v - dp[v]<<endl;
}