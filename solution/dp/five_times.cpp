#include <iostream>
#include <stdout.h>

using namespace std;


int dp[1005];
int lose[1005],win[1005],use[1005];
int n,x;

void solution(){
    cin>>n>>x;
    for(int i = 1;i <= n;i++) cin>>lose[i]>>win[i]>>use[i];

    for(int i = 1;i <= n;i++){
        for(int j = x; j >= use[i];j--){
            dp[j] = max(dp[j] + lose[i],dp[j - use[i]] + win[i]);
        }

        for(int j = 0; j < use[i];j++){
            dp[j] += lose[i];
        }
    }
    printf("%lld",5 * dp[x]);
}