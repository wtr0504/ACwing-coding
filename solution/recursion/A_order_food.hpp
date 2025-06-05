#include "../common.hpp"


vector<int> dp(10005,0);
vector<int> cost(105,0);
void a_order_food(int N,int M){
    dp[0] = 1;
    for(int i = 0;i < N;i++){
        for(int j = M;j >= cost[i];j--){
            dp[j] += dp[j - cost[i]];
        }
    }
}

void solution(){
    int N,M;
    cin>>N>>M;
    for(int i = 0;i < N;i++){
        cin>>cost[i];
    }
    a_order_food(N,M);
    cout<<dp[M]<<endl;
}