#include "../common.hpp"
/**
显然若当前要处理的问题的时间和为t，最佳答案是t/2，也就是两边脑所耗时间差为0。

于是现在要求的问题就是使得两边脑所耗时间差尽量小。

于是我想到了二分，胡乱分析一番，想不出来先放一边。进一步分析。

如果只考虑一边脑耗时，由于两边脑是对称的，我们假设这个耗时肯定比t/2小。那么我们要使这个耗时尽量接近t/2。

然后又想到了背包。保证比t/2小，又要使取得的价值尽量大，可以转化为一个费用与价值相同的背包问题。背包大小为t/2，一个题目的费用和价值相等，都是所耗的时间。
 */
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