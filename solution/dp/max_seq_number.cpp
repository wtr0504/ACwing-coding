#include <iostream>

using namespace std;

int dp[200005];
int a[200005];

int n;
void solution(){
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    for(int i = 1;i <= n;i++){
        dp[i] = max(dp[i-1] + a[i],a[i]);
    }
    cout<<*max_element(dp + 1,dp + 1 + n)<<endl;
}