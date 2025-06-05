#include "../common.hpp"

/**
 * 1. 放2*1的砖头：
 *      1）竖着放 f(n) = f(n - 1);
 *      2) 横着放   f(n) = f(n - 2);
 * 2. 放L型砖头：每种有两种方式 需要* 2 
 *      1）放两个L f(n) = f(n - 3)
 *      2）放一个L 横放一个2*1 再放一个L f(n) = f(n - 4)
 *      3）放一个L 再交替放2*1 最后放一个L 放满 f(n) = f(n - 5) + f(n - 6) + ... f(0)
 * 
 * 使用前缀和避免重算
 */

vector<int> dp(1000005);
vector<int> prefix(1000005);

#define MOD(x) ((x) % 10000)

void cover_wall(){
    int n;
    cin>>n;
    dp[0] = 1;
    prefix[0] = 1;
    for(int i = 1;i <= n;i++){
        dp[i] = MOD((i >= 1 ? prefix[i - 1]: 0) + (i >= 3 ? prefix[i - 3] : 0));
        prefix[i] = MOD(prefix[i - 1] + dp[i]);
    }
    cout<<dp[n]<<endl;
}

void solution(){
    cover_wall();
}