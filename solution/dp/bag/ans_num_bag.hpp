using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <utility>
#include <vector>
#include <iomanip>
#include <tuple>
#include <map>

const int MOD = 1e9 + 7;

void ans_num_bag(){
    int n,v;
    while(cin>>n>>v){
        int res = 0;
        int m = 0;
        vector<int> weight(n);
        vector<int> value(n);
        for(int i = 0;i < n;i++){
            cin>>weight[i]>>value[i];
        }
        vector<int> dp(v + 1,0);

        //  cnt[j]表示容量为 j 时最多的方案
        vector<int> cnt(v + 1,0);
        cnt[0] = 1;
        for(int i = 0;i < n;i++){
            for(int j = v;j >= weight[i];j--){
                int new_val = dp[j - weight[i]] + value[i];
                if(new_val > dp[j]){
                    dp[j] = new_val;
                    cnt[j] = cnt[j - weight[i]];
                } else if(new_val == dp[j]){ // 容量为 j 时，每一种之前的状态加上当前物品都能变成一个新的方案
                    cnt[j] += cnt[j - weight[i]];
                    cnt[j] %= MOD;
                }
            }
        }
        int maxVal = 0;
        for(int i = 0;i <=v;i++){
            if(maxVal < dp[i]){
                maxVal = dp[i];
                res = cnt[i];
            }else if(maxVal == dp[i]){
                res += cnt[i];
                res %= MOD;
            }
        }
        cout<<res<<endl;
    }
}

void solution(){
    ans_num_bag();
}