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

/**
 * 用递归深度遍历，返回该root节点的最大value
 */

void dfs(int root,int v,vector<vector<int>> & dependence,vector<vector<int>>& dp,vector<int> &weight,vector<int> &value){
    // 先只选取该物品
    for(int i = weight[root];i <=v;i++){
        dp[root][i] = value[root]; 
    }
    
    for(auto & child : dependence[root]){
        // 选取value最大的子物品
        dfs(child,v,dependence,dp,weight,value);
        for(int j = v;j >= weight[root];j--){
            // 遍历子物品 
            for(int k = 0;k <= j - weight[root];k++){
                dp[root][j] = max(dp[root][j],dp[root][j - k] + dp[child][k]);
            }
        }
    }

}

void relay_bag(){
    int n,v;
    while(cin>>n>>v){
        vector<int> weight(n);
        vector<int> value(n);
        vector<vector<int>> dependence(n);
        int root = -1;
        for(int i = 0;i < n;i++){
            int d;
            cin>>weight[i]>>value[i]>>d;
            if(d == -1)
                root = i;
            else
                dependence[d-1].push_back(i);
        }
        vector<vector<int>> dp(n,vector<int>(v + 1,0));

        dfs(root,v,dependence,dp,weight,value);
        int res = 0;
        for (int j = 0; j <= v; ++j)
            res = max(res, dp[root][j]); // 找出最大值

        cout << res << endl;
    }
}

void solution(){
    relay_bag();
}