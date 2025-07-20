#include <iostream>

using namespace std;

int val[1005];
int weight[1005];

long long dp[10000005];
int t,m;


void solution(){
    cin>>t>>m;
    for(int i = 1;i <= m;i++){
        cin>>weight[i]>>val[i];
    }

    for(int i = 1;i <= m;i++){
        for(int j = weight[i];j <= t;j++){
            dp[j] = max(dp[j],dp[j - weight[i]] + val[i]);
        }
    }
    cout<<dp[t]<<endl;
}