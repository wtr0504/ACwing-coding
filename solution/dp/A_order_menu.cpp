#include <iostream>


using namespace std;

int m,n;
int dp[10005];
int a[1005];

void solution(){
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }

    dp[0] = 1;

    for(int i = 1;i <= n;i++){
        for(int j = m;j >= a[i];j--){
            dp[j] += dp[j - a[i]];
        }
    }
    cout<<dp[m]<<endl;
}

