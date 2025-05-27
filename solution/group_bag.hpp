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

/**
 * 增加 weight 的维度，遍历组内的物品
 */

void group_bag(){
    int n,v;
    while(cin>>n>>v){
        vector<int> group(n);
        vector<vector<int>> weight(n);
        vector<vector<int>> value(n);
        for(int i = 0;i < n;i++){
            cin>>group[i];
            weight[i] = (vector<int>(group[i]));
            value[i] = (vector<int>(group[i]));
            for(int j = 0;j < group[i];j++){
                cin>>weight[i][j]>>value[i][j];
            }
        }
        vector<int> dp(v + 1,0);
        for(int i = 0;i < n;i++){
            for(int j = v;j >= 0;j--){
                for(int k = 0;k < group[i];k++){
                    if(j >= weight[i][k]){
                        dp[j] = max(dp[j],dp[j - weight[i][k]] + value[i][k]);
                    }
                }
            }
        }
        cout<<dp[v]<<endl;
    }
}

void solution(){
    group_bag();
}