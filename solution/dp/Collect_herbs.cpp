#include <iostream>

using namespace std;

int dp[1005];
struct herb{
int val,time;
};
herb a[105];
int t,v;
int T,n;

void solution(){
    cin>>T>>n;
    for(int i = 1;i <= n;i++){
        cin>>a[i].time>>a[i].val;
    }

    for(int i = 1;i<= n;i++){
        for(int j = T;j >= a[i].time;j--){
            dp[j] = max(dp[j],dp[j - a[i].time] + a[i].val);
        }
    }
    cout<<dp[T]<<endl;
}