#include <iostream>
using namespace std;

int a[105];
int dp[105];
int n,m;
const int mod = 1000007;

void solution(){
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    dp[0] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = m;j >= 0;j--){
            for(int k = 1; k <= min(a[i],j);k++){
                dp[j] = (dp[j] + dp[j - k]) % mod;
            }
        }
    }
    cout<<dp[m]<<endl;
}

