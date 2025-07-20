#include <iostream>
using namespace std;

int n,w;
int a[1005],dp[10005];
const int mod = 1e9 + 7;
void solution(){
    cin>>n>>w;
    for(int i = 1;i <= n;i++) cin>>a[i];

    dp[0] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = a[i];j <= w;j++){
            dp[j] += dp[j - a[i]];
            dp[j] %= mod;
        }
    }
    cout<<dp[w]<<endl;
}