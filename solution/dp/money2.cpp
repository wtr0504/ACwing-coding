#include <iostream>
using namespace std;
int n,w;
int dp[10005];
int a[1005];
const int mod=1e9+7;
void solution(){
    cin>>n>>w;
    for(int i = 1;i <= n;i++)cin>>a[i];

    dp[0] = 1;
    for(int i = 1;i <= w;i++){
        for(int j = 1;j <= n;j++){
            if(i >= a[j]){
                dp[i] = (dp[i] + dp[i - a[j]]) % mod;
            }
        }
    }
    cout<<dp[w]<<endl;
}


