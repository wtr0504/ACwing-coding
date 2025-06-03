#include "../common.hpp"


vector<int> dp(1003);
void number_cnt(int n){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= i /2;j++){
            dp[i] += dp[j];
        }
        dp[i]++;
    }
}

void solution(){
    int n;
    cin>>n;
    int res = 0;
    number_cnt(n);
    cout<<dp[n]<<endl;       
}