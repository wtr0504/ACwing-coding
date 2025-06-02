#include "../common.hpp"

vector<int> nums(21);
vector<int> dp(601);

void kkksc03_exam(){

    int res = 0;
    vector<int> a(5);
    for(int i=1;i <= 4;i++) cin>>a[i];

    for(int i = 1;i <= 4;i++){
        int sum = 0;
        for(int j = 1;j <= a[i];j++){
            cin>>nums[j];
            sum += nums[j];
        }
        for(int j = 1;j <= a[i];j++){
            for(int k = sum / 2;k >= nums[j];k--){
                dp[k] = max(dp[k],dp[k - nums[j]] + nums[j]);
            }
        }
        res += max(dp[sum/2],sum - dp[sum/2]);
        for(int j = 0;j <= sum /2;j++) dp[j] = 0;
    }
    cout<<res<<endl;
}

void solution(){
    while (true)
    {
    kkksc03_exam();
        
    }
    
}